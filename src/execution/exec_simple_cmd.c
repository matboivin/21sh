/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:16:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 19:22:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function executes a simple command
*/

static void	invoke_builtin(t_simplecmd *simple_cmd)
{
	(*simple_cmd->builtin_func)(simple_cmd->argc, simple_cmd->cmd_args);
}

void		exec_simple_cmd(t_shctrl *ft_sh, t_simplecmd *simple_cmd)
{
	redirect_stream(simple_cmd->input_fd, STDIN_FILENO);
	redirect_stream(simple_cmd->output_fd, STDOUT_FILENO);
	if (simple_cmd->cmd_path)
	{
		if (simple_cmd->builtin_func)
			invoke_builtin(simple_cmd);
		else
			execve(simple_cmd->cmd_path, simple_cmd->cmd_args, g_env);
	}
	exit_shell(ft_sh);
}
