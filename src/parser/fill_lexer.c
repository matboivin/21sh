/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:56:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 18:55:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft_str.h"
#include "lexer.h"

/*
** A lexer (Lexical Analyzer​) splits the command into tokens
*/

static t_regex	g_regex_list[] =
{
	{ "&&", 2, TOKEN_DBLAND },
	{ "||", 2, TOKEN_DBLOR },
	{ ">>", 2, TOKEN_REDIR },
	{ ">", 1, TOKEN_REDIR },
	{ "<", 1, TOKEN_REDIR },
	{ ";", 1, TOKEN_SEMICOLON },
	{ "|", 1, TOKEN_PIPE },
	{ "&", 1, TOKEN_AND },
	{ "\n", 1, TOKEN_NEWLINE }, // bonus: eat
	{ " ", 1, TOKEN_EAT },
	{ "\v", 1, TOKEN_EAT },
	{ "\t", 1, TOKEN_EAT },
	{ "\r", 1, TOKEN_EAT },
	{ "\f", 1, TOKEN_EAT },
	{ NULL, 1, NOT_FOUND }
};

t_regex			get_token_type(char *linebuffer)
{
	int			i;

	i = 0;
	while (i < MAX_TOKENS)
	{
		if (!ft_strncmp(g_regex_list[i].op, linebuffer, g_regex_list[i].size))
			return (g_regex_list[i]);
		i++;
	}
	return (g_regex_list[i]);
}

bool			fill_lexer(char *linebuffer, t_lexer *lexer)
{
	t_regex		current_regex;
	//const char*	prev;

	(void)lexer;
	//prev = linebuffer;
	while (linebuffer && *linebuffer)
	{
		current_regex = get_token_type(linebuffer);
		if (current_regex.type)
		{
			// if (prev != linebuffer)
			// add_token_to_lexer(t_lexer, create_token(linebuffer, size_t size, t_token_type type))
		}
		linebuffer++;
	}
	return (true);
}
