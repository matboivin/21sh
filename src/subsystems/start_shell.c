/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 20:30:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sh_env.h"
#include "sh_termcaps.h"
#include "sh_subsystems.h"

volatile sig_atomic_t	g_done;
volatile sig_atomic_t	g_status;

/*
** Shell startup
** This function loads environment, sets flags and registers signal handlers
**
** envp: The environment represented as an array of strings
*/

void	start_shell(char **envp)
{
	load_environment(envp);
	if (BONUS)
		init_term_data();
	g_done = false;
	g_status = EXIT_SUCCESS;
	register_signal_handlers();
}
