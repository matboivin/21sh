/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 17:41:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function checks the redirection operator
** Expected operators: LESS ('<'), GREAT ('>') or DGREAT ('>>')
*/

static t_ast_node	*parse_redir_op(t_lexer *lexer, size_t *pos)
{
	t_ast_node		*result;

	result = NULL;
	if (
		(is_expected_type(lexer->tokens[*pos]->type, TOKEN_LESS))
		|| (is_expected_type(lexer->tokens[*pos]->type, TOKEN_GREAT))
		|| (is_expected_type(lexer->tokens[*pos]->type, TOKEN_DGREAT)))
	{
		result = malloc_ast_node(NODE_IO_FILE, lexer->tokens[*pos]->value);
		if (result)
		{
			(*pos)++;
			return (result);
		}
	}
	return (NULL);
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
** returns: A new IO file node
**          NULL otherwise
*/

t_ast_node			*parse_io_file(t_lexer *lexer, size_t *pos)
{
	t_ast_node		*io_file_node;
	t_ast_node		*word_node;

	io_file_node = NULL;
	word_node = NULL;
	io_file_node = parse_redir_op(lexer, pos);
	if (io_file_node)
	{
		word_node = parse_word(lexer, pos);
		if (word_node)
		{
			append_node_right(&io_file_node, word_node);
			return (io_file_node);
		}
		free_ast(&io_file_node);
	}
	return (NULL);
}
