/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 19:04:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function checks the redirection operator
** Expected operators: LESS ('<'), GREAT ('>') or DGREAT ('>>')
*/

static bool		parse_redir_op(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	t_ast_node	*iofile_node;

	iofile_node = NULL;
	if (
		(is_expected_type(lexer->tokens[*pos]->type, TOKEN_LESS))
		|| (is_expected_type(lexer->tokens[*pos]->type, TOKEN_GREAT))
		|| (is_expected_type(lexer->tokens[*pos]->type, TOKEN_DGREAT)))
	{
		iofile_node = malloc_ast_node(NODE_IO_FILE, lexer->tokens[*pos]->value);
		if (iofile_node)
		{
			append_node_right(ast, iofile_node);
			(*pos)++;
			return (true);
		}
	}
	return (false);
}

/*
** This function parses an IO file
**
** Grammar rule:
** io_file : '<'       WORD
**         | '>'       WORD
**         | '>>'      WORD
**
** NODE_IO_FILE
**      |
**   "operator"
**       \
**     NODE_WORD
**         |
**     "filename"
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool			parse_io_file(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	if (parse_redir_op(ast, lexer, pos))
	{
		if (parse_word(&(*ast)->right, lexer, pos))
			return (true);
		(*pos)--;
		free_ast(ast);
	}
	return (false);
}
