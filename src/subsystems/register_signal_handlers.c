/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_signal_handlers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:14:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 18:17:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "ft_subsystems.h"
#include "ft_sh.h"

// ENOTRECOVERABLE

void	register_signal_handlers(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR)
		exit_error();
	if (signal(SIGQUIT, signal_handler) == SIG_ERR)
		exit_error();
}
