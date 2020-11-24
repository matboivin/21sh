/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:47:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/24 20:53:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "sh_utils.h"
#include "sh_input_processing.h"

static void	handle_eof(t_shctrl *ft_sh)
{
	ft_putchar('\n');
	exit_ft_sh(g_status, ft_sh);
}

/*
** This function prompts the user for an input
*/

char		*prompt(t_shctrl *ft_sh, const char *prompt)
{
	char	*result;

	result = ft_readline(prompt);
	if (!result)
		handle_eof(ft_sh);
	return (result);
}
