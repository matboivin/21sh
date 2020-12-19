/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/19 12:01:10 by mboivin          ###   ########.fr       */
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

// TODO: redirs and pipes

void		execute(t_shctrl *ft_sh, t_cmd *cmd)
{
	pid_t	pid;
	int		pfd[2];
	int		wstatus;
	size_t	i;

	i = 0;
	while (i < cmd->cmd_count)
	{
		create_pipe(ft_sh, pfd);
		spawn_process(ft_sh, &pid);
		if (is_child_process(pid))
			exec_simple_cmd(ft_sh, cmd->simple_cmds[i]);
		i++;
	}
	waitpid(pid, &wstatus, DEFAULT_VALUE);
	if (WIFEXITED(wstatus))
		g_status = WEXITSTATUS(wstatus);
}
