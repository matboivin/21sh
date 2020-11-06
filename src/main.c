/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 19:54:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "ft_sh.h"

volatile sig_atomic_t	g_done; // tmp

int			main(int argc, char **argv, char **envp)
{
	g_done = 0;

	(void)argv;
	if (argc != DEFAULT_ARGC)
		print_usage();
	init_env(envp);
	register_signal_handlers();
	return (listen());
}
