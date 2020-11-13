/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 15:22:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_lexer.h"

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
	{ "\n", 1, TOKEN_NEWLINE },
	{ " ", 1, TOKEN_EAT },
	{ "\\", 1, TOKEN_EAT },
	{ "\v", 1, TOKEN_EAT },
	{ "\t", 1, TOKEN_EAT },
	{ "\r", 1, TOKEN_EAT },
	{ "\f", 1, TOKEN_EAT },
	{ NULL, 1, NOT_FOUND }
};

t_regex			get_token_type(char *input)
{
	int			i;

	i = 0;
	while (i < MAX_TOKENS)
	{
		if (!ft_strncmp(g_regex_list[i].op, input, g_regex_list[i].size))
			return (g_regex_list[i]);
		i++;
	}
	return (g_regex_list[i]);
}

bool			fill_lexer(char *input, t_lexer *lexer)
{
	t_regex		current_regex;
	//const char*	prev;

	(void)lexer;
	//prev = input;
	while (input && *input)
	{
		current_regex = get_token_type(input);
		if (current_regex.type)
		{
			ft_printf("Regex: %s\n", current_regex.op);
			input += current_regex.size;
		}
		else
		{
			ft_printf("Input: %s\n", input);
			input += ft_strlen(input);
		}
	}
	return (true);
}
