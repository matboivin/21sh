/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 15:19:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sh_env.h"

volatile sig_atomic_t	g_done;
volatile sig_atomic_t	g_status;

/*
** Shell startup
** This function loads environment and sets flags
**
** envp: The environment represented as an array of strings
*/

void	start_shell(char **envp)
{
	g_done = false;
	g_status = EXIT_SUCCESS;
	load_environment(envp);
}
