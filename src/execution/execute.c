/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/18 21:02:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "libft_printf.h"
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
	size_t	i;
	int		wstatus;
	pid_t	pid;

	i = 0;
	while (i < cmd->cmd_count)
	{
		spawn_process(ft_sh, &pid);
		if (is_child_process(pid))
			exec_simple_cmd(ft_sh, cmd->simple_cmds[i]);
		i++;
	}
	waitpid(pid, &wstatus, DEFAULT_VALUE);
	if (WIFEXITED(wstatus))
		g_status = WEXITSTATUS(wstatus);
}
