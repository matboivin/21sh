/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:25:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 18:40:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function spawns a new process
*/

void	spawn_process(pid_t *pid)
{
	if ((*pid = fork()) == FAIL_RET)
		print_error("fork");
}
