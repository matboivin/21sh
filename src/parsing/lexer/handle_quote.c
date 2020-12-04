/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:17:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 21:19:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_utils.h"
#include "sh_lexer.h"

static void	close_quote(t_lexer *lexer, char **input, char **stack)
{
	*stack = push_char(*stack, input);
	handle_text(lexer, stack);
}

static void	raise_matching_error(char **stack, char quote_type)
{
	ft_strdel(stack);
	print_matching_error(quote_type);
}

static void	handle_quote_type(t_lexer *lexer, char **input, char quote_type)
{
	char	*stack;

	stack = NULL;
	stack = push_char(stack, input);
	while (**input && **input != quote_type)
	{
		if ((**input == BACKSLASH) && (quote_type == WEAK_QUOTE))
			escape_char(input, &stack);
		else
			stack = push_char(stack, input);
	}
	if (**input == quote_type)
		close_quote(lexer, input, &stack);
	else
		raise_matching_error(&stack, quote_type);
}

void		handle_quotes(t_lexer *lexer, char **input)
{
	if (**input == STRONG_QUOTE)
		handle_quote_type(lexer, input, STRONG_QUOTE);
	else if (**input == WEAK_QUOTE)
		handle_quote_type(lexer, input, WEAK_QUOTE);
}
