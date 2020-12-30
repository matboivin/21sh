/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_seq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 23:41:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function checks whether the current simple command is the last one
*/

static bool		is_last_command(t_cmd *cmd)
{
	return (cmd->curr_cmd == (cmd->cmd_count - 1));
}

/*
** This function checks whether a process is a child process
*/

static bool		is_child_process(pid_t pid)
{
	return (pid == 0);
}

/*
** This function creates a pipe object
*/

static void		create_pipe(t_shctrl *ft_sh, t_streams *redir)
{
	int	pfd[2];

	if (pipe(pfd) == FAIL_RET)
	{
		print_errno("pipe");
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
	redir->in = pfd[READ_END];
	redir->out = pfd[WRITE_END];
}

/*
** This function executes a pipe sequence
**
** The output of each command in the pipeline is connected via a pipe to the
** input of the next command. That is, each command reads the previous
** command’s output. This connection is performed before any redirections
** specified by the command.
*/

void			exec_pipe_seq(t_shctrl *ft_sh, t_cmd *cmd)
{
	pid_t		pid;
	t_streams	backup;
	t_streams	redir;
	int			wstatus;

	pid = -1;
	wstatus = -1;
	dup_streams(&backup);
	redir.in = dup(backup.in);
	while (cmd->curr_cmd < cmd->cmd_count)
	{
		redirect_stream(redir.in, STDIN_FILENO);
		redir.out = dup(backup.out);
		if (!is_last_command(cmd))
			create_pipe(ft_sh, &redir);
		redirect_stream(redir.out, STDOUT_FILENO);
		spawn_process(ft_sh, &pid);
		if (is_child_process(pid))
		{
			exec_simple_cmd(cmd->simple_cmds[cmd->curr_cmd]);
			exit_shell(ft_sh);
		}
		cmd->curr_cmd++;
	}
	restore_default_streams(backup);
	waitpid(pid, &wstatus, DEFAULT_VALUE);
	if (WIFEXITED(wstatus))
		g_status = WEXITSTATUS(wstatus);
}
