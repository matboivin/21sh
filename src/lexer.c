/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 01:27:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/01 14:10:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

t_token		create_token(char *content, size_t size, t_token_type type)
{
	t_token	result;

	result.content = ft_strnew(size);
	ft_strlcpy(result.content, content, size);
	result.size = size;
	result.type = type;
	return (result);
}

void		create_lexer(t_lexer *lexer, size_t capacity)
{
	lexer->tokens = (t_token *)ft_calloc(capacity, sizeof(t_token));
	lexer->size = 0;
	lexer->capacity = capacity;
}

void		add_token_to_lexer(t_lexer *lexer, t_token new_token)
{
	if (lexer->size == lexer->capacity)
	{
		lexer->capacity *= 2;
		lexer->tokens = (t_token *)reallocarray(
			lexer->tokens, lexer->size, (lexer->capacity * sizeof(t_token)));
	}
	lexer->size++;
	lexer->tokens[lexer->size] = new_token;
}

void		destroy_lexer(t_lexer *lexer)
{
	free(lexer->tokens);
	lexer->size = 0;
	lexer->capacity = 0;
}
