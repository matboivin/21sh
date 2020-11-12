/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 21:25:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_lexer.h"

/*
** Tokens
*/

t_token		create_token(char *content, size_t size, t_token_type type)
{
	t_token	result;

	result.size = size;
	result.type = type;
	result.content = ft_strnew(size);
	ft_strlcpy(result.content, content, (size + 1));
	return (result);
}

void		add_token_to_lexer(t_lexer *lexer, t_token new_token)
{
	if (lexer->size == lexer->capacity)
	{
		lexer->capacity *= 2;
		lexer->tokens = reallocarray(
			lexer->tokens, lexer->capacity, sizeof(t_token));
	}
	lexer->size += 1;
	lexer->tokens[lexer->size] = new_token;
}
