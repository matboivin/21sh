/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:16:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/18 19:06:28 by mboivin          ###   ########.fr       */
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
	if (simple_cmd->in_fd != -1)
		redirect_to_file(simple_cmd->in_fd, STDIN_FILENO);
	if (simple_cmd->out_fd != -1)
		redirect_to_file(simple_cmd->out_fd, STDOUT_FILENO);
	execve(
		simple_cmd->cmd_path,
		simple_cmd->cmd_args,
		g_env);
	exit_shell(ft_sh);
}
