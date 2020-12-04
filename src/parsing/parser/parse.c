/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 21:26:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_parser.h"

/*
** This function processes the tokens into an Abstract Syntax Tree (AST)
**
** ast: The AST to complete
** lexer: The lexer containing the tokens
** pos: The position in the lexer
*/

int		parse(t_ast_node **ast, t_lexer *lexer)
{
	bool	ret_val;

	ret_val = true;
	create_tree_root(ast);
	while ((lexer->pos < lexer->size) && ret_val)
		ret_val = parse_command(ast, lexer);
	if (lexer->pos != lexer->size)
	{
		ft_dprintf(STDERR_FILENO, "parser: Grammar error\n");
		return (FAIL_RET);
	}
	return (0);
}
