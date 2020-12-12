/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:51:19 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/12 17:31:24 by ouram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function registers signal handlers
*/

void	register_signal_handlers(void)
{
	if (signal(SIGINT, handle_fatal_error) == SIG_ERR)
	{
		ft_clearenv();
		exit(EXIT_FAILURE);
	}
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		ft_clearenv();
		exit(EXIT_FAILURE);
	}
}
