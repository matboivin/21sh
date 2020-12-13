/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/13 16:00:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function checks the redirection operator
** Expected operators: LESS ('<'), GREAT ('>') or DGREAT ('>>')
*/

static bool		parse_redir_op(t_ast_node **ast, t_lexer *lexer)
{
	if (
		(lexer->tokens[lexer->pos]->type == TOKEN_LESS)
		|| (lexer->tokens[lexer->pos]->type == TOKEN_GREAT)
		|| (lexer->tokens[lexer->pos]->type == TOKEN_DGREAT))
	{
		(*ast)->data = lexer->tokens[lexer->pos]->value;
		get_next_token(lexer);
		return (true);
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
**      |
**  NODE_WORD
**      |
**  "filename"
**
** returns: true if the node creation succeeded
**          false otherwise
*/

bool			parse_io_file(t_ast_node **ast, t_lexer *lexer)
{
	t_ast_node	*iofile_node;

	if (lexer->pos >= lexer->size)
		return (false);
	iofile_node = malloc_ast_node(NODE_IO_FILE, NULL);
	if (parse_redir_op(&iofile_node, lexer))
	{
		if (parse_word(&(iofile_node->right), lexer))
		{
			append_node_left(ast, iofile_node);
			return (true);
		}
		lexer->pos -= 1;
	}
	free_ast(&iofile_node);
	return (false);
}
