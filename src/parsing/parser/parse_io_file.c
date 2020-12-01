/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_io_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/01 20:01:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "sh_parser.h"

/*
** This function parses an IO file
**
** returns: A new IO file struct
**          NULL otherwise
*/

t_io_file	*parse_io_file(t_lexer *lexer, size_t pos)
{
	t_tok_type	tok_type;
	t_io_file	*result;

	result = NULL;
	if (
		(is_expected_type(lexer->tokens[pos]->type, TOKEN_LESS))
		|| (is_expected_type(lexer->tokens[pos]->type, TOKEN_GREAT))
		|| (is_expected_type(lexer->tokens[pos]->type, TOKEN_DGREAT)))
	{
		tok_type = lexer->tokens[pos]->type;
		pos++;
		if (is_expected_type(lexer->tokens[pos]->type, TOKEN_WORD))
		{
			result = malloc_io_file(tok_type, lexer->tokens[pos]->value);
			pos++;
			return (result);
		}
	}
	return (NULL);
}
