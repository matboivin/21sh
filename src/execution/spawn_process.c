/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:25:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/18 19:46:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function spawns a new process
*/

void	spawn_process(t_shctrl *ft_sh, pid_t *pid)
{
	if ((*pid = fork()) == FAIL_RET)
	{
		print_error("fork", strerror(errno));
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
}
