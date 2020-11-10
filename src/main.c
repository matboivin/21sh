/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 18:00:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "libft_io.h"
#include "libft_printf.h"
#include "ft_sh.h"

volatile sig_atomic_t	g_done;
volatile sig_atomic_t	g_status;

int			main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != DEFAULT_ARGC)
		print_usage();
	g_done = false;
	g_status = EXIT_SUCCESS;
	init_env(envp);
	register_signal_handlers();
	return (shell_loop());
}
