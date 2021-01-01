/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:29 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 18:59:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

void	handle_token(t_lexer *lexer, t_regex token, char **stack)
{
	if (*stack && stack)
		add_text_to_lexer(lexer, stack);
	if (token.type != TOKEN_EAT)
		add_token_to_lexer(lexer, token.op, token.len, token.type);
	lexer->pos += token.len;
}
