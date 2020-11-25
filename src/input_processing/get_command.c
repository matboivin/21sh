/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/25 14:43:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_utils.h"
#include "sh_lexer.h"
#include "sh_input_processing.h"

/*
** This function gets the command input
*/

int			get_command(t_shctrl *ft_sh)
{
	int		ret;
	char	*user_input;

	user_input = prompt(ft_sh, SHELL_PROMPT);
	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	ret = tokenize(ft_sh->lexer, user_input);
	ft_strdel(&user_input);
	while (ret)
	{
		user_input = prompt(ft_sh, LINE_PROMPT);
		ret = tokenize(ft_sh->lexer, user_input);
		ft_strdel(&user_input);
	}
#ifdef DEBUG
	print_lexer(ft_sh->lexer);
#endif /* DEBUG */
	free_lexer(&(ft_sh->lexer));
	return (g_status);
}
