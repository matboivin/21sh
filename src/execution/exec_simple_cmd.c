/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:16:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/21 23:29:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function executes a simple command
*/

void	exec_simple_cmd(t_shctrl *ft_sh, t_simplecmd *simple_cmd)
{
	redirect_stream(simple_cmd->input_fd, STDIN_FILENO);
	redirect_stream(simple_cmd->output_fd, STDOUT_FILENO);
	if (simple_cmd->cmd_path)
	{
		if (simple_cmd->builtin_func)
		{
			ft_printf("Executing builtin %s\n\n", simple_cmd->cmd_args[CMD_NAME]); // debug
			(*simple_cmd->builtin_func)(simple_cmd->argc, simple_cmd->cmd_args);
		}
		else
			execve(simple_cmd->cmd_path, simple_cmd->cmd_args, g_env);
	}
	exit_shell(ft_sh);
}
