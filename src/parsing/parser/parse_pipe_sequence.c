/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_sequence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:04:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 19:43:51 by mboivin          ###   ########.fr       */
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
**      NODE_PIPE_SEQ
**            |
**     NODE_SIMPLE_CMD
**            |
**           ...
**
** returns: true if the node creation succeeded
**          false otherwise
*/

// TODO: loop

bool	parse_pipe_sequence(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	t_ast_node	*pipe_node;
	t_ast_node	*pipe2;

	pipe_node = malloc_ast_node(NODE_PIPE_SEQ, "|");
	if (parse_simple_cmd(&pipe_node->left, lexer, pos))
	{
		append_node_right(ast, pipe_node);
		if ((*pos < lexer->size) && lexer->tokens[*pos]->type == TOKEN_PIPE)
		{
			(*pos)++;
			pipe2 = malloc_ast_node(NODE_PIPE_SEQ, "|");
			if (parse_simple_cmd(&pipe2->left, lexer, pos))
				append_node_right(ast, pipe2);
			else
				free_ast(&pipe2);
		}
		return (true);
	}
	free_ast(&pipe_node);
	return (false);
}
