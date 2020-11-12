/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 18:24:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_input_processing.h"

static void	handle_eof(char *user_input)
{
	if (!user_input)
	{
		ft_putchar('\n');
		exit_ft_sh(EXIT_SUCCESS);
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
	free_all();
	return (g_status);
}
