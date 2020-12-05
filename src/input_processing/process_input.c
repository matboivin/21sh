/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 21:12:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_parser.h"
#include "sh_input_processing.h"

/*
** This function gets the command input and splits it into tokens
*/

static void	get_command(t_shctrl *ft_sh)
{
	int		not_finished;

	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	ft_sh->lexer->input = display_prompt(ft_sh, FT_PS1);
	not_finished = tokenize(ft_sh->lexer, ft_sh->lexer->input);
	ft_strdel(&ft_sh->lexer->input);
	while (not_finished)
	{
		ft_sh->lexer->input = display_prompt(ft_sh, FT_PS2);
		not_finished = tokenize(ft_sh->lexer, ft_sh->lexer->input);
		ft_strdel(&ft_sh->lexer->input);
	}
}

/*
** This function processes the command input
*/

int			process_input(t_shctrl *ft_sh)
{
	get_command(ft_sh);
	parse(&(ft_sh->ast), ft_sh->lexer);
#ifdef DEBUG
	print_lexer(ft_sh->lexer);
	print_ast(ft_sh->ast);
#endif /* DEBUG */
	destroy_shell(ft_sh);
	return (g_status);
}
