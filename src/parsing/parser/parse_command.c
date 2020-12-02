/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:04:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 20:08:27 by mboivin          ###   ########.fr       */
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
** returns: true if the node creation succeeded
**          false otherwise
*/

bool	parse_command(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	// TODO
}
