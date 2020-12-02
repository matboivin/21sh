/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 18:29:51 by mboivin          ###   ########.fr       */
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

bool			parse_word(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	t_ast_node	*word_node;

	word_node = NULL;
	if (is_expected_type(lexer->tokens[*pos]->type, TOKEN_WORD))
	{
		word_node = malloc_ast_node(NODE_WORD, lexer->tokens[*pos]->value);
		if (word_node)
		{
			append_node_right(ast, word_node);
			(*pos)++;
			return (true);
		}
	}
	return (false);
}
