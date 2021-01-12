/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:23:14 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/13 00:13:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function eats the current token if its type is the one expected
**
** returns: 1 if a token was eaten
**          0 otherwise
*/

int		eat(t_lexer *lexer, t_tok_type expected)
{
	if ((lexer->pos < lexer->size) && (lexer->tokens[lexer->pos]->type == expected))
	{
		get_next_token(lexer);
		return (1);
	}
	return (0);
}
