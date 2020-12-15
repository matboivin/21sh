/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:16:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:32:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function executes a simple command
*/

void	exec_simple_cmd(t_shctrl *ft_sh, t_simplecmd *simple_cmd)
{
	execve(
		simple_cmd->cmd_args[CMD_NAME],
		simple_cmd->cmd_args,
		g_env);
	print_error(simple_cmd->cmd_args[CMD_NAME]);
	exit_shell(ft_sh);
}
