/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:04:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 20:31:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a command
**
** Grammar rule:
** command :              pipe_sequence
**         | command SEMI pipe_sequence
**
**              NODE_CMD
**              /      \
**  NODE_PIPE_SEQ      NODE_CMD
**                     /      \
**         NODE_PIPE_SEQ      NODE_CMD
**                            /      \
**                          ...      ...
**
** returns: true if the node creation succeeded
**          false otherwise
*/

static bool		get_pipe_seq(t_ast_node **node, t_lexer *lexer, size_t *pos)
{
	t_ast_node	*cmd_node;

	cmd_node = malloc_ast_node(NODE_CMD, "command");
	if (parse_pipe_sequence(&cmd_node->left, lexer, pos))
	{
		append_node_right(node, cmd_node);
		if ((*pos < lexer->size) && lexer->tokens[*pos]->type == TOKEN_SEMI)
			(*pos)++;
		return (true);
	}
	free_ast(&cmd_node);
	return (false);
}

bool			parse_command(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	bool		parsed;

	parsed = get_pipe_seq(ast, lexer, pos);
	if (parsed)
	{
		while ((*pos < lexer->size) && parsed)
			parsed = get_pipe_seq(ast, lexer, pos);
		return (true);
	}
	return (false);
}
