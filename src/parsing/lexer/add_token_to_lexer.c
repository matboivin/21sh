/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_lexer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:03:31 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 23:04:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function adds a token to the lexer
*/

void	add_token_to_lexer(
	t_lexer *lexer, const char *s, size_t p_len, t_tok_type p_type)
{
	if (lexer_is_full(lexer))
		increase_lexer(lexer);
	lexer->tokens[lexer->size] = malloc_token(s, p_len, p_type);
	lexer->size += 1;
}
