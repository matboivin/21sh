/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:04:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/13 16:04:11 by mboivin          ###   ########.fr       */
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

static bool		get_pipe_seq(t_ast_node **node, t_lexer *lexer)
{
	t_ast_node	*cmd_node;

	cmd_node = malloc_ast_node(NODE_CMD, NULL);
	if (parse_pipe_sequence(&cmd_node->left, lexer))
	{
		append_node_right(node, cmd_node);
		eat(lexer, TOKEN_SEMI);
		return (true);
	}
	free_ast(&cmd_node);
	return (false);
}

bool			parse_command(t_ast_node **ast, t_lexer *lexer)
{
	bool		parsed;

	parsed = get_pipe_seq(ast, lexer);
	if (parsed)
	{
		while ((lexer->pos < lexer->size) && parsed)
			parsed = get_pipe_seq(ast, lexer);
		return (true);
	}
	return (false);
}
