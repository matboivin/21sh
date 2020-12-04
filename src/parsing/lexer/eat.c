/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:23:14 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 21:36:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

int		eat(t_lexer *lexer, t_tok_type expected)
{
	if (
		(lexer->pos < lexer->size)
		&& (lexer->tokens[lexer->pos]->type == expected))
	{
		lexer->pos += 1;
		return (1);
	}
	return (0);
}
