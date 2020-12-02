/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 17:34:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses an IO file
**
** returns: A new IO file node
**          NULL otherwise
*/

static t_ast_node	*parse_redir_op(t_lexer *lexer, size_t *pos)
{
	t_ast_node		*result;

	result = NULL;
	if (
		(is_expected_type(lexer->tokens[*pos]->type, TOKEN_LESS))
		|| (is_expected_type(lexer->tokens[*pos]->type, TOKEN_GREAT))
		|| (is_expected_type(lexer->tokens[*pos]->type, TOKEN_DGREAT)))
	{
		result = malloc_ast_node(NODE_IO_FILE, lexer->tokens[*pos]->value);
		if (result)
		{
			(*pos)++;
			return (result);
		}
	}
	return (NULL);
}

t_ast_node			*parse_io_file(t_lexer *lexer, size_t *pos)
{
	t_ast_node		*node;
	t_ast_node		*child_node;

	node = NULL;
	child_node = NULL;
	node = parse_redir_op(lexer, pos);
	if (node)
	{
		child_node = parse_word(lexer, pos);
		if (child_node)
		{
			append_node_right(&node, child_node);
			return (node);
		}
		free_ast(&node);
	}
	return (NULL);
}
