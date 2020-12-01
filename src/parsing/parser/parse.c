/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/01 20:00:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function processes the tokens into an Abstract Syntax Tree (AST)
**
** ast: The AST to complete
** lexer: The lexer containing the tokens
** pos: The position in the lexer
*/

void			parse(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	t_io_file	*new_expr;

	new_expr = NULL;
	if (*ast)
	{
		new_expr = parse_io_file(lexer, *pos);
		if (new_expr)
		{
			append_node_left(ast, malloc_ast_node(NODE_IO_FILE, new_expr));
			*pos += 2;
		}
	}
	else
	{
		create_tree_root(ast);
		(*pos)++;
	}
}
