/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 21:54:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "libft_mem.h"
#include "sh_env.h"
#include "sh_subsystems.h"

volatile sig_atomic_t	g_status;
volatile sig_atomic_t	g_done;
volatile sig_atomic_t	g_char_dev;

/*
** Shell startup
** This function loads environment, sets flags and registers signal handlers
**
** envp: The environment represented as an array of strings
*/

void	start_shell(char **envp)
{
	if (!(*envp))
	{
		// SHELL, SHLVL, USER
	}
	else
		load_environment(envp);
	g_status = EXIT_SUCCESS;
	g_done = false;
	g_char_dev = false;
	register_signal_handlers();
}
