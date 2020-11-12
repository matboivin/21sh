/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 21:31:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_input_processing.h"

static void	handle_eof(char *user_input, t_shctrl ft_sh)
{
	if (!user_input)
	{
		ft_putchar('\n');
		exit_ft_sh(EXIT_SUCCESS, ft_sh);
	}
}

int			shell_loop(t_shctrl ft_sh)
{
	char	*user_input;

	while (!g_done)
	{
		user_input = ft_readline(SHELL_PROMPT);
		handle_eof(user_input, ft_sh);
		// TODO: Feed lexer, parse and execute
		fill_lexer(user_input, ft_sh.lexer);
		ft_strdel(&user_input);
	}
	free_all(ft_sh);
	return (g_status);
}
