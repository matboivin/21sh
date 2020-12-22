/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:17:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 18:43:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_utils.h"
#include "sh_lexer.h"

static int	close_quote(t_lexer *lexer, char **stack)
{
	*stack = push_char(lexer, *stack);
	handle_text(lexer, stack);
	return (0);
}

static int	raise_matching_error(char **stack, char quote_type)
{
	ft_strdel(stack);
	handle_matching_error(quote_type);
	return (FAIL_RET);
}

static int	handle_quote_type(t_lexer *lexer, char quote_type)
{
	char	*stack;

	stack = NULL;
	stack = push_char(lexer, stack);
	while (lexer->input[lexer->pos] && lexer->input[lexer->pos] != quote_type)
	{
		if (
			(lexer->input[lexer->pos] == BACKSLASH)
			&& (quote_type == WEAK_QUOTE))
			escape_char(lexer, &stack);
		else
			stack = push_char(lexer, stack);
	}
	if (lexer->input[lexer->pos] == quote_type)
		return (close_quote(lexer, &stack));
	else
		return (raise_matching_error(&stack, quote_type));
}

int			handle_quotes(t_lexer *lexer)
{
	if (lexer->input[lexer->pos] == STRONG_QUOTE)
		return (handle_quote_type(lexer, STRONG_QUOTE));
	return (handle_quote_type(lexer, WEAK_QUOTE));
}
