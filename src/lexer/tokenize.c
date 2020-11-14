/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 22:00:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"
#include "sh_utils.h"

/*
** This function splits the input string into tokens and handles syntax errors
*/

static int		raise_syntax_error(const char *token)
{
	g_status = INCORRECT_USAGE;
	print_syntax_error(token);
	return (FAIL_RET);
}

static int		is_quote(char c)
{
	return ((c == '\"') || (c == '\''));
}

static int		raise_matching_error(char **input)
{
	char		c;

	c = **input;
	(*input)++;
	while (**input && !is_quote(**input))
		(*input)++;
	if (!*input || !is_quote(**input))
	{
		g_status = INCORRECT_USAGE;
		print_match_error(c);
		return (1);
	}
	(*input)++;
	return (0);
}

int				tokenize(t_lexer *lexer, char *input)
{
	t_regex		found;
	const char	*backup;

	backup = input;
	while (input && *input)
	{
		found = search_token(input);
		if (found.type == TOKEN_ERR)
			return(raise_syntax_error(found.op));
		if ((found.type || is_quote(*input)) && backup != input)
			add_token_to_lexer(lexer, backup, (input - backup), TOKEN_TEXT);
		if (found.type)
		{
			if (found.type != TOKEN_EAT)
				add_token_to_lexer(lexer, found.op, found.len, found.type);
			input += found.len;
			backup = input;
		}
		else if (is_quote(*input))
		{
			if (raise_matching_error(&input))
				return (FAIL_RET);
		}
		else
			input++;
	}
	if (backup != input)
		add_token_to_lexer(lexer, backup, (input - backup), TOKEN_TEXT);
	return (0);
}
