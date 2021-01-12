/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_suffix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:40:16 by mboivin          ###   ########.fr       */
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
**        /                 /        \                    \
**    NODE_WORD       NODE_WORD   NODE_IO_FILE       NODE_IO_FILE
**        |                |           |                  |
**    NODE_WORD           ...         ...            NODE_IO_FILE
**
** returns: true if the node creation succeeded
**          false otherwise
*/

static bool		get_suffix_word(t_ast_node **node, t_lexer *lexer)
{
	bool		parsed;

	parsed = parse_word(node, lexer);
	if (parsed)
	{
		while ((lexer->pos < lexer->size) && parsed)
			parsed = parse_word(node, lexer);
		return (true);
	}
	return (false);
}

static bool		get_suffix_file(t_ast_node **node, t_lexer *lexer)
{
	bool		parsed;

	parsed = parse_io_file(node, lexer);
	if (parsed)
	{
		while ((lexer->pos < lexer->size) && parsed)
			parsed = parse_io_file(node, lexer);
		return (true);
	}
	return (false);
}

bool			parse_cmd_suffix(t_ast_node **ast, t_lexer *lexer)
{
	bool		parsed_word;
	bool		parsed_file;
	t_ast_node	*suffix_node;

	if (lexer->pos >= lexer->size)
		return (false);
	suffix_node = malloc_ast_node(NODE_CMD_SUFFIX, NULL);
	do
	{
		parsed_word = get_suffix_word(&suffix_node->left, lexer);
		parsed_file = get_suffix_file(&suffix_node->right, lexer);
	} while (parsed_word || parsed_file);
	if (suffix_node->left || suffix_node->right)
	{
		append_node_right(ast, suffix_node);
		return (true);
	}
	free_ast(&suffix_node);
	return (false);
}
