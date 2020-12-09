/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/08 14:32:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_lexer.h"

/*
** This function splits the input string into tokens
*/

int			tokenize(t_lexer *lexer)
{
	t_regex	token;
	char	*stack;

	stack = NULL;
	lexer->pos = 0;
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
		else if (
			(lexer->input[lexer->pos] == STRONG_QUOTE)
			|| (lexer->input[lexer->pos] == WEAK_QUOTE))
			handle_quotes(lexer);
		else if (token.type)
			handle_token(lexer, token, &stack);
		else
			stack = push_char(lexer, stack);
	}
	if (stack)
		handle_text(lexer, &stack);
	return (EXIT_SUCCESS);
}
