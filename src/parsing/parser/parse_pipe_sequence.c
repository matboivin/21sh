/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_sequence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:04:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 21:35:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a pipe sequence
**
** Grammar rule:
** pipe_sequence :                    simple_command
**               | pipe_sequence PIPE simple_command
**
**              NODE_PIPE_SEQ
**              /           \
**  NODE_SIMPLE_CMD      NODE_PIPE_SEQ
**                       /           \
**           NODE_SIMPLE_CMD      NODE_PIPE_SEQ
**                                /           \
**                              ...           ...
**
** returns: true if the node creation succeeded
**          false otherwise
*/

static bool		get_simple_cmd(t_ast_node **node, t_lexer *lexer)
{
	t_ast_node	*pipe_node;

	pipe_node = malloc_ast_node(NODE_PIPE_SEQ, "|");
	if (parse_simple_cmd(&pipe_node->left, lexer))
	{
		append_node_right(node, pipe_node);
		eat(lexer, TOKEN_PIPE);
		return (true);
	}
	free_ast(&pipe_node);
	return (false);
}

bool			parse_pipe_sequence(t_ast_node **ast, t_lexer *lexer)
{
	bool		parsed;

	parsed = get_simple_cmd(ast, lexer);
	if (parsed)
	{
		while ((lexer->pos < lexer->size) && parsed)
			parsed = get_simple_cmd(ast, lexer);
		return (true);
	}
	return (false);
}
