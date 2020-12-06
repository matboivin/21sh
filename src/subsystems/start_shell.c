/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/06 18:39:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_subsystems.h"

volatile sig_atomic_t	g_done;
volatile sig_atomic_t	g_status;

/*
** Shell startup
** This function loads environment, sets flags and registers signal handlers
**
** envp: The environment represented as an array of strings
*/

void		create_prompt(void)
{
	char	*custom_prompt;

	custom_prompt = ft_join_n_str(
		5, "FT_PS1", "=", OP_PROMPT, ft_getenv("SHELL"), END_PROMPT);
	if (custom_prompt)
		ft_putenv(custom_prompt);
}

void	start_shell(char **envp, char *argv0)
{
	load_environment(envp, argv0);
	create_prompt();
	g_done = false;
	g_status = EXIT_SUCCESS;
	register_signal_handlers();
}
