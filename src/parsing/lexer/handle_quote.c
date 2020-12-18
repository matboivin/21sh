/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:17:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/18 20:40:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_utils.h"
#include "sh_lexer.h"

static void	close_quote(t_lexer *lexer, char **stack)
{
	*stack = push_char(lexer, *stack);
	handle_text(lexer, stack);
}

static void	raise_matching_error(char **stack, char quote_type)
{
	ft_strdel(stack);
	handle_matching_error(quote_type);
}

static void	handle_quote_type(t_lexer *lexer, char quote_type)
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
		close_quote(lexer, &stack);
	else
		raise_matching_error(&stack, quote_type);
}

void		handle_quotes(t_lexer *lexer)
{
	if (lexer->input[lexer->pos] == STRONG_QUOTE)
		handle_quote_type(lexer, STRONG_QUOTE);
	else if (lexer->input[lexer->pos] == WEAK_QUOTE)
		handle_quote_type(lexer, WEAK_QUOTE);
}
