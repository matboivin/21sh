/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 20:03:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a simple command
**
** Grammar rule:
** simple_command : io_file WORD cmd_suffix
**                | io_file WORD
**                |         WORD cmd_suffix
**                | io_file
**                |         WORD
**
**            NODE_SIMPLE_CMD
**           /       |       \
** NODE_IO_FILE  NODE_WORD  NODE_CMD_SUFFIX
**
**      NODE_SIMPLE_CMD               NODE_SIMPLE_CMD
**        /         \                  /         \
** NODE_IO_FILE    NODE_WORD     NODE_WORD      NODE_CMD_SUFFIX
**
** NODE_SIMPLE_CMD      NODE_SIMPLE_CMD
**        |                    |
**    NODE_WORD           NODE_IO_FILE
**        |
**    "cmd_name"
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool	parse_simple_cmd(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	if (parse_io_file(ast, lexer, pos))
	{
		if (parse_word(ast, lexer, pos))
			parse_cmd_suffix(ast, lexer, pos);
		return (true);
	}
	if (parse_word(ast, lexer, pos))
	{
		parse_cmd_suffix(ast, lexer, pos);
		return (true);
	}
	return (parse_io_file(ast, lexer, pos));
}
