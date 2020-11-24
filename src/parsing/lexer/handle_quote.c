/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:17:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/24 20:07:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_utils.h"
#include "sh_lexer.h"

static void	close_quote(t_lexer *lexer, char **input, char **stack)
{
	*stack = eat(*stack, input);
	handle_text(lexer, stack);
}

void		handle_quote(t_lexer *lexer, char **input, char quote_type)
{
	char	*stack;

	stack = NULL;
	stack = eat(stack, input);
	while (**input && **input != quote_type)
	{
		if (**input == BACKSLASH)
			escape_char(input, &stack);
		else
			stack = eat(stack, input);
	}
	if (**input == quote_type)
		close_quote(lexer, input, &stack);
	else
	{
		ft_strdel(&stack);
		print_matching_error(quote_type);
	}
}
