/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe_sequence.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:04:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 20:07:58 by mboivin          ###   ########.fr       */
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
** returns: true if the node creation succeeded
**          false otherwise
*/

bool	parse_pipe_sequence(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	// TODO
}
