/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:25:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/19 21:24:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		print_errno("fork");
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
}
