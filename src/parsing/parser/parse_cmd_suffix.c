/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_suffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/13 16:01:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a command suffix
**
** Grammar rule:
** cmd_suffix :            io_file
**            | cmd_suffix io_file
**            |            WORD
**            | cmd_suffix WORD
**
** NODE_CMD_SUFFIX         NODE_CMD_SUFFIX         NODE_CMD_SUFFIX
**        |                 /        \                    |
**    NODE_WORD       NODE_WORD   NODE_IO_FILE       NODE_IO_FILE
**        |                |           |                  |
**    NODE_WORD           ...         ...            NODE_IO_FILE
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool			parse_cmd_suffix(t_ast_node **ast, t_lexer *lexer)
{
	t_ast_node	*suffix_node;

	if (lexer->pos >= lexer->size)
		return (false);
	suffix_node = malloc_ast_node(NODE_CMD_SUFFIX, NULL);
	if (parse_word(&suffix_node, lexer))
	{
		parse_io_file(&(suffix_node->right), lexer);
		append_node_left(ast, suffix_node);
		return (true);
	}
	else if (parse_io_file(&suffix_node, lexer))
	{
		append_node_left(ast, suffix_node);
		return (true);
	}
	free_ast(&suffix_node);
	return (false);
}
