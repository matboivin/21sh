/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 17:33:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses a Word
**
** returns: A new Word node
**          NULL otherwise
*/

t_ast_node		*parse_word(t_lexer *lexer, size_t *pos)
{
	t_ast_node	*result;

	result = NULL;
	if (is_expected_type(lexer->tokens[*pos]->type, TOKEN_WORD))
	{
		result = malloc_ast_node(NODE_WORD, lexer->tokens[*pos]->value);
		if (result)
		{
			(*pos)++;
			return (result);
		}
	}
	return (NULL);
}
