/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 21:36:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

void	handle_token(t_lexer *lexer, t_regex token, char **stack)
{
	if (*stack && stack)
		handle_text(lexer, stack);
	if (token.type != TOKEN_EAT)
		add_token_to_lexer(lexer, token.op, token.len, token.type);
	lexer->pos += token.len;
}
