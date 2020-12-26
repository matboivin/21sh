/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 01:58:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

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

static void		exec_builtin(t_simplecmd *simple_cmd)
{
	redirect_stream(simple_cmd->input_fd, STDIN_FILENO);
	redirect_stream(simple_cmd->output_fd, STDOUT_FILENO);
	invoke_builtin(simple_cmd);
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

	pid = -1;
	wstatus = -1;
	backup_streams(&backup, &(pipe_redir.input));
	while (cmd->curr_cmd < cmd->cmd_count)
	{
		redirect_stream(pipe_redir.input, STDIN_FILENO);
		pipe_redir.output = dup(backup.output);
		if (is_last_command(cmd) && is_builtin(cmd->simple_cmds[cmd->curr_cmd]))
			exec_builtin(cmd->simple_cmds[cmd->curr_cmd]);
		else
			spawn_process(ft_sh, cmd, &pid, &pipe_redir);
		cmd->curr_cmd++;
	}
	restore_default_streams(backup);
	waitpid(pid, &wstatus, DEFAULT_VALUE);
	if (WIFEXITED(wstatus))
		g_status = WEXITSTATUS(wstatus);
}
