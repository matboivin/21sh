/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/22 19:21:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
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
		token = search_token(input);
		if (*input == COMMENT_START)
			break ;
		if (*input == STRONG_QUOTE)
			handle_quote(lexer, &input, STRONG_QUOTE);
		else if (*input == WEAK_QUOTE)
			handle_quote(lexer, &input, WEAK_QUOTE);
		else if (token.type)
			input += handle_token(lexer, token, &stack);
		else
			stack = ft_strpushc(stack, &input);
	}
	if (stack)
		handle_text(lexer, &stack);
	return (EXIT_SUCCESS);
}
