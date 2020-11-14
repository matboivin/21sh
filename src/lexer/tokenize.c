/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:21:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_printf.h"
#include "sh_lexer.h"

/*
** This function splits the input string into tokens and handles syntax errors
*/

// static int		raise_syntax_error(const char *token)
// {
// 	ft_dprintf(
// 		STDERR_FILENO,
// 		"syntax error near unexpected token `%s'\n",
// 		token);
// 	return (FAIL_RET);
// }

int				tokenize(t_lexer *lexer, char *input)
{
	t_regex		found;
	const char	*backup;

	backup = input;
	while (input && *input)
	{
		found = search_token(input);
		if (found.type && backup != input)
			add_token_to_lexer(lexer, backup, (input - backup), TOKEN_TEXT);
		if (found.type)
		{
			if (found.type == TOKEN_BACKSLASH)
			{
				//TODO: handle escaping
			}
			else if (found.type != TOKEN_EAT)
				add_token_to_lexer(lexer, found.op, found.len, found.type);
			input += found.len;
			backup = input;
		}
		else
			input++;
	}
	if (backup != input)
		add_token_to_lexer(lexer, backup, (input - backup), TOKEN_TEXT);
	return (0);
}
