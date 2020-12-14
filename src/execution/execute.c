/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 18:37:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sh_execution.h"

static bool	is_child_process(pid_t pid)
{
	return (pid == 0);
}

/*
** This function executes all simple commands
*/

void		execute(t_cmd *cmd)
{
	size_t	i;
	int		wstatus;
	pid_t	pid;

	i = 0;
	while (i < cmd->cmd_count)
	{
		/* Create child process */
		spawn_process(&pid);
		if (is_child_process(pid))
			exec_simple_cmd(cmd->simple_cmds[i]);
		i++;
	}
	waitpid(pid, &wstatus, DEFAULT_VALUE);
}
