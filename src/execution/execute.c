/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/19 23:04:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sh_execution.h"

static bool		is_child_process(pid_t pid)
{
	return (pid == 0);
}

static void		restore_default_streams(t_streams backup)
{
	redirect_stream(backup.input, STDIN_FILENO);
	redirect_stream(backup.output, STDIN_FILENO);
}

static void		backup_streams(t_streams *backup, int *input)
{
	backup->input = dup(STDIN_FILENO);
	backup->output = dup(STDOUT_FILENO);
	*input = dup(backup->input);
}

/*
** This function executes all simple commands
*/

void			execute(t_shctrl *ft_sh, t_cmd *cmd)
{
	pid_t		pid;
	t_streams	backup;
	t_streams	pipe_redir;
	int			wstatus;

	backup_streams(&backup, &(pipe_redir.input));
	while (cmd->curr_cmd < cmd->cmd_count)
	{
		redirect_stream(pipe_redir.input, STDIN_FILENO);
		pipe_redir.output = dup(backup.output);
		if (!is_last_command(cmd))
			create_pipe(ft_sh, &pipe_redir);
		redirect_stream(pipe_redir.output, STDOUT_FILENO);
		spawn_process(ft_sh, &pid);
		if (is_child_process(pid))
			exec_simple_cmd(ft_sh, cmd->simple_cmds[cmd->curr_cmd]);
		cmd->curr_cmd++;
	}
	restore_default_streams(backup);
	waitpid(pid, &wstatus, DEFAULT_VALUE);
	if (WIFEXITED(wstatus))
		g_status = WEXITSTATUS(wstatus);
}
