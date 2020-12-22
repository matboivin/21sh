/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 18:34:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_utils.h"
#include "sh_parser.h"

/*
** This function processes the tokens into an Abstract Syntax Tree (AST)
**
** ast: The AST to complete
** lexer: The lexer containing the tokens
**
** returns: 0
**          -1 on error
*/

int			parse(t_ast_node **ast, t_lexer *lexer)
{
	bool	ret_val;

	ret_val = true;
	lexer->pos = 0;
	create_tree_root(ast);
	while ((lexer->pos < lexer->size) && ret_val)
		ret_val = parse_command(ast, lexer);
	if (lexer->pos != lexer->size)
	{
		handle_syntax_error(lexer->tokens[lexer->pos]->value);
		return (FAIL_RET);
	}
	return (0);
}
