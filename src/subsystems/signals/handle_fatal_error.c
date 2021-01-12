/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fatal_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:52:28 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:32:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <signal.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function handles fatal errors
**
** The return value of a command is its exit status, or 128 + N if the command
** is terminated by signal N
*/

void		handle_fatal_error(int sig)
{
	char	*shell_prompt;

	shell_prompt = NULL;
	if (sig == SIGINT)
	{
		g_status = FATAL_ERROR + sig;
		ft_printf("\n");
		if (!g_char_dev)
		{
			shell_prompt = create_prompt();
			ft_printf("%s", shell_prompt);
			ft_strdel(&shell_prompt);
		}
		g_char_dev = false;
	}
}
