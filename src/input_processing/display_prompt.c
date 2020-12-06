/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:47:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/06 18:57:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "sh_utils.h"
#include "sh_input_processing.h"

/*
** This function exits if end of input was indicated
*/

static void	handle_eof(t_shctrl *ft_sh)
{
	ft_putchar('\n');
	exit_shell(ft_sh, g_status);
}

/*
** This function prompts the user for an input
*/

char		*display_prompt(t_shctrl *ft_sh, const char *prompt)
{
	char	*result;

	result = ft_readline(prompt);
	if (!result)
		handle_eof(ft_sh);
	return (result);
}
