/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 20:12:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function invokes a shell builtin
*/

void	invoke_builtin(t_simplecmd *builtin)
{
	redirect_stream(builtin->input_fd, STDIN_FILENO);
	redirect_stream(builtin->output_fd, STDOUT_FILENO);
	if (builtin->cmd_path)
		g_status = (*builtin->builtin_func)(builtin->argc, builtin->cmd_args);
}

/*
** This function executes a simple command
*/

void	exec_simple_cmd(t_simplecmd *simple_cmd)
{
	if (is_builtin(simple_cmd))
		invoke_builtin(simple_cmd);
	else
	{
		redirect_stream(simple_cmd->input_fd, STDIN_FILENO);
		redirect_stream(simple_cmd->output_fd, STDOUT_FILENO);
		if (simple_cmd->cmd_path)
			execve(simple_cmd->cmd_path, simple_cmd->cmd_args, g_env);
		print_errno(simple_cmd->cmd_args[CMD_NAME]);
	}
}

/*
** This function executes all simple commands
** When a simple command other than a builtin is to be executed, it is invoked
** in a child process
*/

void	execute(t_shctrl *ft_sh, t_cmd *cmd)
{
	if (cmd->cmd_count == 1 && is_sh_builtin(cmd->simple_cmds[cmd->curr_cmd]))
		invoke_builtin(cmd->simple_cmds[cmd->curr_cmd]);
	else
		exec_pipe_seq(ft_sh, cmd);
}
