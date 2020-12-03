/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/03 18:23:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a simple command
**
** Grammar rule:
** simple_command : io_file cmd_name cmd_suffix
**                | io_file cmd_name
**                | io_file
**                |         cmd_name cmd_suffix
**                |         cmd_name
**
**      NODE_SIMPLE_CMD                 NODE_SIMPLE_CMD
**             |                               |
**         "cmd_name"                      NODE_IO_FILE
**
**      NODE_SIMPLE_CMD                  NODE_SIMPLE_CMD
**        /         \                     /         \
** NODE_IO_FILE   "cmd_name"        "cmd_name"      NODE_CMD_SUFFIX
**
**                        NODE_SIMPLE_CMD
**                       /       |       \
**             NODE_IO_FILE  "cmd_name"  NODE_CMD_SUFFIX
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool	parse_simple_cmd(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	t_ast_node	*simple_cmd_node;

	simple_cmd_node = malloc_ast_node(NODE_SIMPLE_CMD, "simple_cmd");
	if (parse_io_file(&simple_cmd_node, lexer, pos))
	{
		if (*pos < lexer->size)
		{
			if (parse_word(&(simple_cmd_node->right), lexer, pos))
			{
				if (*pos < lexer->size)
					parse_cmd_suffix(&(simple_cmd_node->right), lexer, pos);
			}
		}
		append_node_left(ast, simple_cmd_node);
		return (true);
	}
	else if (parse_word(&simple_cmd_node, lexer, pos))
	{
		if (*pos < lexer->size)
			parse_cmd_suffix(&(simple_cmd_node->left), lexer, pos);
		append_node_left(ast, simple_cmd_node);
		return (true);
	}
	free_ast(&simple_cmd_node);
	return (false);
}
