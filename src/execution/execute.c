/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 23:46:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function invokes a shell builtin
*/

void			invoke_builtin(t_simplecmd *builtin)
{
	if (builtin->cmd_path)
		g_status = (*builtin->builtin_func)(builtin->argc, builtin->cmd_args);
}

/*
** This function executes a simple command
*/

void			exec_simple_cmd(t_simplecmd *simple_cmd)
{
	t_streams	backup;

	handle_redirection(simple_cmd, &backup);
	if (simple_cmd->cmd_path)
	{
		if (is_builtin(simple_cmd))
			invoke_builtin(simple_cmd);
		else
		{
			execve(simple_cmd->cmd_path, simple_cmd->cmd_args, g_env);
			print_errno(simple_cmd->cmd_args[CMD_NAME]);
		}
	}
	restore_default_streams(backup);
}

/*
** This function executes all simple commands
** When a simple command other than a builtin is to be executed, it is invoked
** in a child process
*/

void			execute(t_shctrl *ft_sh, t_cmd *cmd)
{
	if (cmd->cmd_count == DEFAULT_VALUE)
		return ;
	if (cmd->cmd_count == 1 && is_builtin(cmd->simple_cmds[cmd->curr_cmd]))
		exec_simple_cmd(cmd->simple_cmds[cmd->curr_cmd]);
	else
		exec_pipe_seq(ft_sh, cmd);
}
