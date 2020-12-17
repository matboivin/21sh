/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/17 19:18:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "sh_env.h"
#include "sh_subsystems.h"

volatile sig_atomic_t	g_status;
volatile sig_atomic_t	g_done;

/*
** Shell startup
** This function loads environment, sets flags and registers signal handlers
**
** envp: The environment represented as an array of strings
*/

void	start_shell(char **envp, char *argv0)
{
	load_environment(envp, argv0);
	create_prompt();
	g_status = EXIT_SUCCESS;
	g_done = false;
	register_signal_handlers();
}
