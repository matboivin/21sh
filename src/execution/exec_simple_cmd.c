/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 18:08:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include "sh_utils.h"
#include "sh_execution.h"

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
