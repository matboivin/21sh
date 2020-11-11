/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 14:53:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_input_processing.h"

static void	handle_eof(char *user_input)
{
	if (!user_input)
	{
		ft_printf("\n");
		ft_clearenv();
		exit(EXIT_SUCCESS);
	}
}

int			shell_loop(void)
{
	char	*user_input;

	while (!g_done)
	{
		user_input = ft_readline(SHELL_PROMPT);
		handle_eof(user_input);
		ft_strdel(&user_input); // TODO: Feed lexer, parse and execute
	}
	ft_clearenv();
	return (g_status);
}
