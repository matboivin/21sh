/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:29:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "sh_utils.h"
#include "sh_lexer.h"
#include "sh_input_processing.h"

/*
** This function parses the command input
*/

static void	handle_eof(t_shctrl *ft_sh)
{
	ft_putchar('\n');
	exit_ft_sh(EXIT_SUCCESS, ft_sh);
}

int			parse_command(t_shctrl *ft_sh, char *user_input)
{
	if (!user_input)
		handle_eof(ft_sh);
	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	tokenize(ft_sh->lexer, user_input);
	print_lexer(ft_sh->lexer);
	free_lexer(&(ft_sh->lexer));
	return (0);
}
