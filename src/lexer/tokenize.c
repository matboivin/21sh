/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/15 16:00:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"
#include "sh_utils.h"

/*
** This function raises a syntax error
*/

static int		raise_syntax_error(const char *token)
{
	g_status = INCORRECT_USAGE;
	print_syntax_error(token);
	return (FAIL_RET);
}

// static int		raise_matching_error(char **input)
// {
// 	g_status = INCORRECT_USAGE;
// 	print_match_error(**input);
// 	return (FAIL_RET);
// }

/*
** This function splits the input string into tokens and handles syntax errors
*/

int				tokenize(t_lexer *lexer, char *input)
{
	t_regex		found;
	const char	*backup;

	backup = input;
	while (input && *input)
	{
		found = search_token(input);
		if (found.type == TOKEN_HASH) // Handle comment
			return (0);
		else if (found.type == TOKEN_ERR) // Handle syntax error
			return (raise_syntax_error(found.op));
		else if (found.type == TOKEN_QUOTE) // Handle quoting/escaping
		{
			// TODO
		}
		else if (found.type)
		{
			if (backup != input)
				add_token_to_lexer(lexer, backup, (input - backup), TOKEN_TEXT);
			else if (found.type != TOKEN_EAT)
				add_token_to_lexer(lexer, found.op, found.len, found.type);
			input += found.len;
			backup = input;
		}
		else
			input++;
	}
	if (backup != input) // Remainder
		add_token_to_lexer(lexer, backup, (input - backup), TOKEN_TEXT);
	return (0);
}
