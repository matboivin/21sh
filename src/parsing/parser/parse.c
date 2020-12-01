/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/01 17:15:55 by mboivin          ###   ########.fr       */
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
	(void)lexer;
	(void)pos;
	if (!ast)
		create_tree_root(ast);
}
