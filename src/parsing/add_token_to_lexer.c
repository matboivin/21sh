/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_lexer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:03:31 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 21:04:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function adds a token to the lexer
*/

void	add_token_to_lexer(t_lexer *lexer, t_token *new_token)
{
	if (lexer_is_full(lexer))
		increase_lexer(lexer);
	lexer->size += 1;
	lexer->tokens[lexer->size] = new_token;
}
