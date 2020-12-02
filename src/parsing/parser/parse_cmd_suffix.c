/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_suffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 20:02:15 by mboivin          ###   ########.fr       */
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
**        |               |
**      "args"          "args"
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool	parse_cmd_suffix(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	if (parse_word(ast, lexer, pos))
	{
		parse_io_file(ast, lexer, pos);
		return (true);
	}
	return (parse_io_file(ast, lexer, pos));
}
