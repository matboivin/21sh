/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:29 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:39:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function handles each encountered token, ignores EAT tokens (tabs,
** spaces) and adds them to the lexer, then increments the index on the string
** input
*/

void	handle_token(t_lexer *lexer, t_regex token, char **tok_stack)
{
	if (*tok_stack && tok_stack)
		add_word_to_lexer(lexer, tok_stack);
	if (token.type != TOKEN_EAT)
		add_token_to_lexer(lexer, token.op, token.len, token.type);
	lexer->pos += token.len;
}
