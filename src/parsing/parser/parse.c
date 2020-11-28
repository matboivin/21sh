/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/27 11:51:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_printf.h"
#include "sh_parser.h"

/*
** This function processes the tokens into an Abstract Syntax Tree (AST)
**
** ast: The AST to complete
** lexer: The lexer containing the tokens
** pos: The position in the lexer
*/

void			parse(t_ast_node **ast, t_lexer *lexer, size_t pos)
{
	t_ast_node	*cursor;
	t_ast_node	*left;

	if (*ast)
	{
		cursor = *ast;
		while (cursor)
		{
			left = cursor;
			cursor = cursor->right;
		}
		cursor = malloc_ast_node(
			NODE_TYPE_WORD,
			left,
			NULL,
			lexer->tokens[pos]->value);
		left->right = cursor;
	}
	else
	{
		*ast = malloc_ast_node(
			NODE_TYPE_WORD,
			NULL,
			NULL,
			lexer->tokens[pos]->value);
	}
}
