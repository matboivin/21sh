/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:51:19 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 14:19:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "sh_signal_handling.h"
#include "ft_sh.h"

/*
** Register signal handlers
*/

void	register_signal_handlers(void)
{
	if (signal(SIGINT, handle_fatal_error) == SIG_ERR)
		exit_error("signal");
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		exit_error("signal");
}
