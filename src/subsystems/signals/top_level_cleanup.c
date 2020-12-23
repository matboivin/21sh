/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_level_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:53:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 19:16:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <signal.h>
#include "sh_subsystems.h"

/*
** This function signals cleanup should be performed when we run
** jump_to_top_level() from a builtin command context
*/

void	top_level_cleanup(int sig)
{
	if (sig == SIGUSR1)
		g_done = true;
}
