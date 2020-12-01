/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/01 18:48:51 by mboivin          ###   ########.fr       */
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

bool		is_expected_type(t_tok_type current, t_tok_type expected)
{
	return (current == expected);
}


t_io_file	*parse_io_file(t_lexer *lexer, size_t pos)
{
	t_tok_type	tok_type;
	t_io_file	*result;

	result = NULL;
	if (
		(is_expected_type(lexer->tokens[pos]->type, TOKEN_LESS))
		|| (is_expected_type(lexer->tokens[pos]->type, TOKEN_GREAT))
		|| (is_expected_type(lexer->tokens[pos]->type, TOKEN_DGREAT))
		)
	{
		tok_type = lexer->tokens[pos]->type;
		pos++;
		if (is_expected_type(lexer->tokens[pos]->type, TOKEN_WORD))
		{
			result = malloc_io_file(tok_type, lexer->tokens[pos]->value);
			pos++;
			return (result);
		}
	}
	return (NULL);
}


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
