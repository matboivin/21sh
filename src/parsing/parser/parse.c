/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 18:41:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "sh_utils.h"
#include "sh_parser.h"
#include "libft_printf.h"

/*
** This function processes the tokens into an Abstract Syntax Tree (AST)
**
** ast: The AST to complete
** lexer: The lexer containing the tokens
**
** returns: 0
**          -1 on error
*/

static bool	is_last_token(t_lexer *lexer)
{
	return (lexer->pos == (lexer->size - 1));
}

static int	print_syntax_error(t_lexer *lexer)
{
	if (is_last_token(lexer))
		handle_syntax_error("newline");
	else
		handle_syntax_error(lexer->tokens[lexer->pos]->value);
	return (FAIL_RET);
}

int			parse(t_ast_node **root, t_lexer *lexer)
{
	bool	parsed;

	parsed = true;
	lexer->pos = 0;
	create_tree_root(root);
	while ((lexer->pos < lexer->size) && parsed)
		parsed = parse_command(root, lexer);
	if (lexer->pos < lexer->size)
		return (print_syntax_error(lexer));
#ifdef DEBUG
	print_ast(*root);
#endif /* DEBUG */
	return (0);
}
