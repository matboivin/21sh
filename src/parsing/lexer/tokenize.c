/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 21:19:30 by mboivin          ###   ########.fr       */
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
		token = get_token(input);
		if (*input == COMMENT_START)
			break ;
		if (*input == BACKSLASH)
		{
			if (escape_char(&input, &stack))
				return (1);
		}
		else if ((*input == STRONG_QUOTE) || (*input == WEAK_QUOTE))
			handle_quotes(lexer, &input);
		else if (token.type)
			input += handle_token(lexer, token, &stack);
		else
			stack = push_char(stack, &input);
	}
	if (stack)
		handle_text(lexer, &stack);
	return (EXIT_SUCCESS);
}
