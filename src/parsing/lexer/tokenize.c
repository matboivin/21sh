/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 18:54:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_lexer.h"

/*
** This function splits the input string into tokens
*/

// TODO: Norm (25 lines)

static int	is_quote(int c)
{
	return ((c == STRONG_QUOTE) || (c == WEAK_QUOTE));
}

int			tokenize(t_lexer *lexer)
{
	t_regex	token;
	char	*stack;

	stack = NULL;
	lexer->pos = DEFAULT_VALUE;
	while (lexer->input[lexer->pos])
	{
		token = get_token(lexer->input + lexer->pos);
		if (lexer->input[lexer->pos] == COMMENT_START)
			break ;
		if (lexer->input[lexer->pos] == BACKSLASH)
		{
			if (escape_char(lexer, &stack))
				return (1);
		}
		else if (is_quote(lexer->input[lexer->pos]))
		{
			if (handle_quotes(lexer) == FAIL_RET)
				return (FAIL_RET);
		}
		else if (token.type)
			handle_token(lexer, token, &stack);
		else
			stack = push_char(lexer, stack);
	}
	if (stack)
		handle_text(lexer, &stack);
	return (EXIT_SUCCESS);
}
