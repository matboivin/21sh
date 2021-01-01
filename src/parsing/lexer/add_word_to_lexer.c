/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_word_to_lexer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:04:40 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 19:08:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_lexer.h"

/*
** This function adds a word token (default token type) to the lexer
*/

void	add_word_to_lexer(t_lexer *lexer, char **stack)
{
	add_token_to_lexer(lexer, *stack, ft_strlen(*stack), TOKEN_WORD);
	ft_strdel(stack);
}
