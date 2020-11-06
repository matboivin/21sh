/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:14:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:56:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft_printf.h"
#include "ft_subsystems.h"

// ENOTRECOVERABLE

void	signal_handler(int sig)
{
	g_done = true; // interrupt
	ft_printf("Catched %d\n", sig);
	ft_printf("Quit (core dumped)\n");
}
