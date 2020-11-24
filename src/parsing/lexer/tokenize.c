/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/24 20:40:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_lexer.h"

/*
** This function splits the input string into tokens and handles syntax errors
*/

int			tokenize(t_lexer *lexer, char *input)
{
	t_regex	token;
	char	*stack;

	stack = NULL;
	while (input && *input)
	{
		token = get_next_token(input);
		if (*input == COMMENT_START)
			break ;
		if (*input == BACKSLASH)
			escape_char(&input, &stack);
		else if (*input == STRONG_QUOTE)
			handle_quotes(lexer, &input, STRONG_QUOTE);
		else if (*input == WEAK_QUOTE)
			handle_quotes(lexer, &input, WEAK_QUOTE);
		else if (token.type)
			input += handle_token(lexer, token, &stack);
		else
			stack = eat(stack, &input);
	}
	if (stack)
		handle_text(lexer, &stack);
	return (EXIT_SUCCESS);
}
