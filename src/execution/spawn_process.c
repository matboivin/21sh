/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:25:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 01:59:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

static bool		is_child_process(pid_t pid)
{
	return (pid == 0);
}

/*
** This function spawns a new process
*/

void			spawn_process(
	t_shctrl *ft_sh, t_cmd *cmd, pid_t *pid, t_streams *pipe_redir)
{
	if (!is_last_command(cmd))
		create_pipe(ft_sh, pipe_redir);
	redirect_stream(pipe_redir->output, STDOUT_FILENO);
	if ((*pid = fork()) == FAIL_RET)
	{
		print_errno("fork");
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
	if (is_child_process(*pid))
	{
		exec_simple_cmd(cmd->simple_cmds[cmd->curr_cmd]);
		exit_shell(ft_sh);
	}
}
