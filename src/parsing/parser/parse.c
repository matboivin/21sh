/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 18:54:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "sh_parser.h"

/*
** This function processes the tokens into an Abstract Syntax Tree (AST)
**
** ast: The AST to complete
** lexer: The lexer containing the tokens
** pos: The position in the lexer
*/

bool		parse(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	bool	ret_val;

	ret_val = false;
	if (!(*ast))
		create_tree_root(ast);
	if (*ast)
	{
		ret_val = parse_io_file(ast, lexer, pos);
		if (ret_val)
			return (ret_val);
		ret_val = parse_word(ast, lexer, pos);
	}
	return (ret_val);
}
