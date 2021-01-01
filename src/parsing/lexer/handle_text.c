/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 19:00:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_lexer.h"

void	add_text_to_lexer(t_lexer *lexer, char **stack)
{
	add_token_to_lexer(lexer, *stack, ft_strlen(*stack), TOKEN_WORD);
	ft_strdel(stack);
}

int		handle_text(t_lexer *lexer, char **stack)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (is_quote(lexer->input[lexer->pos]))
		ret = handle_quotes(lexer, stack);
	else
		*stack = push_char(lexer, *stack);
	return (ret);
}
