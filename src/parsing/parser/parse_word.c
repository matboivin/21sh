/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 21:34:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a Word
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool			parse_word(t_ast_node **ast, t_lexer *lexer)
{
	t_ast_node	*word_node;

	word_node = NULL;
	if (lexer->tokens[lexer->pos]->type == TOKEN_WORD)
	{
		word_node = malloc_ast_node(
			NODE_WORD, lexer->tokens[lexer->pos]->value);
		if (word_node)
		{
			lexer->pos += 1;
			append_node_left(ast, word_node);
			return (true);
		}
	}
	return (false);
}
