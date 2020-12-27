/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:16:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/27 19:11:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function invokes a shell builtin
*/

static void	invoke_builtin(t_simplecmd *builtin)
{
	g_status = (*builtin->builtin_func)(builtin->argc, builtin->cmd_args);
}

/*
** This function executes a simple command
*/

void		exec_simple_cmd(t_simplecmd *simple_cmd)
{
	redirect_stream(simple_cmd->input_fd, STDIN_FILENO);
	redirect_stream(simple_cmd->output_fd, STDOUT_FILENO);
	if (simple_cmd->cmd_path)
	{
		if (is_builtin(simple_cmd))
			invoke_builtin(simple_cmd);
		else
			execve(simple_cmd->cmd_path, simple_cmd->cmd_args, g_env);
	}
}
