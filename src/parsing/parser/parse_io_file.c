/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/04 19:44:53 by mboivin          ###   ########.fr       */
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
	if (
		(lexer->tokens[*pos]->type == TOKEN_LESS)
		|| (lexer->tokens[*pos]->type == TOKEN_GREAT)
		|| (lexer->tokens[*pos]->type == TOKEN_DGREAT))
	{
		(*ast)->data = lexer->tokens[*pos]->value;
		(*pos)++;
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

bool			parse_io_file(t_ast_node **ast, t_lexer *lexer, size_t *pos)
{
	t_ast_node	*iofile_node;

	iofile_node = malloc_ast_node(NODE_IO_FILE, NULL);
	if (parse_redir_op(&iofile_node, lexer, pos))
	{
		if (*pos < lexer->size)
		{
			if (parse_word(&iofile_node, lexer, pos))
			{
				append_node_left(ast, iofile_node);
				return (true);
			}
		}
		(*pos)--;
	}
	free_ast(&iofile_node);
	return (false);
}
