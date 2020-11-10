/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 18:02:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_input_processing.h"

int			shell_loop(void)
{
	char	*command;

	while (!g_done)
	{
		command = ft_readline(SHELL_PROMPT);
		ft_strdel(&command);
		// TODO: Feed lexer, parse and execute
	}
	ft_clearenv();
	return (g_status);
}
