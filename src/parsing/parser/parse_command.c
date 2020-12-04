/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:04:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 20:27:37 by mboivin          ###   ########.fr       */
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

bool	parse_command(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	(void)ast;
	(void)lexer;
	(void)pos;
	return (false);
}
