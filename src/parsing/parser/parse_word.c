/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/07 17:13:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "sh_subsystems.h"
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

	word_node = malloc_ast_node(NODE_WORD, lexer->tokens[lexer->pos]->value);
	substitute_word(&(word_node->data));
	if (eat(lexer, TOKEN_WORD) && word_node)
	{
		append_node_left(ast, word_node);
		return (true);
	}
	free_ast(&word_node);
	return (false);
}
