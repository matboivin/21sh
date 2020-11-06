/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:14:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 18:52:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft_printf.h"
#include "subsystems.h"

// ENOTRECOVERABLE

void	signal_handler(int sig)
{
	(void)sig;
	g_done = 1; // interrupt
	ft_printf("\n");
}
