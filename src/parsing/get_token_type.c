/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:16:42 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 21:00:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_lexer.h"

static t_regex	g_regex_list[] =
{
	{ "while", 5, TOKEN_WHILE },
	{ "for", 3, TOKEN_FOR },
	{ "&&", 2, TOKEN_DBLAND },
	{ "||", 2, TOKEN_DBLOR },
	{ ">>", 2, TOKEN_REDIR },
	{ "! ", 2, TOKEN_NEG },
	{ ">", 1, TOKEN_REDIR },
	{ "<", 1, TOKEN_REDIR },
	{ "|", 1, TOKEN_PIPE },
	{ "&", 1, TOKEN_AND },
	{ "=", 1, TOKEN_EQUAL },
	{ ";", 1, TOKEN_SEMICOLON },
	{ "\n", 1, TOKEN_EAT },
	{ " ", 1, TOKEN_EAT },
	{ "\v", 1, TOKEN_EAT },
	{ "\t", 1, TOKEN_EAT },
	{ "\r", 1, TOKEN_EAT },
	{ "\f", 1, TOKEN_EAT },
	{ NULL, 0, NOT_FOUND }
};

/*
** This function searches if input is a token and return its type
*/

t_regex		get_token_type(char *input)
{
	int		i;

	i = 0;
	while (i < MAX_TOKENS)
	{
		if (!ft_strncmp(g_regex_list[i].op, input, g_regex_list[i].len))
			return (g_regex_list[i]);
		i++;
	}
	return (g_regex_list[NOT_FOUND]);
}
