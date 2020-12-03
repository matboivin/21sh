/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_suffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/03 18:19:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a command suffix
**
** Grammar rule:
** cmd_suffix : WORD
**            | WORD io_file
**            |      io_file
**
** NODE_CMD_SUFFIX         NODE_CMD_SUFFIX         NODE_CMD_SUFFIX
**        |                 /        \                    |
**    NODE_WORD       NODE_WORD   NODE_IO_FILE       NODE_IO_FILE
**        |                                               |
**      "args"                                        "operator"
**                                                        |
**                                                    NODE_WORD
**                                                        |
**                                                    "filename"
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool			parse_cmd_suffix(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	t_ast_node	*suffix_node;

	suffix_node = malloc_ast_node(NODE_CMD_SUFFIX, "cmd_suffix");
	if (parse_word(&suffix_node, lexer, pos))
	{
		if (*pos < lexer->size)
			parse_io_file(&(suffix_node->right), lexer, pos);
		append_node_left(ast, suffix_node);
		return (true);
	}
	else if (parse_io_file(&suffix_node, lexer, pos))
	{
		append_node_left(ast, suffix_node);
		return (true);
	}
	free_ast(&suffix_node);
	return (false);
}
