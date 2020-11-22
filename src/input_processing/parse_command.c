/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/22 19:55:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_utils.h"
#include "sh_lexer.h"
#include "sh_input_processing.h"

/*
** This function parses the command input
*/

int		parse_command(t_shctrl *ft_sh, char *user_input)
{
	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	tokenize(ft_sh->lexer, user_input);
#ifdef DEBUG
	print_lexer(ft_sh->lexer);
#endif /* DEBUG */
	free_lexer(&(ft_sh->lexer));
	return (g_status);
}
