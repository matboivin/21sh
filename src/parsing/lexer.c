/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 21:25:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_lexer.h"

/*
** Lexer
*/

void		create_lexer(t_lexer *lexer, size_t capacity)
{
	lexer->size = 0;
	lexer->capacity = capacity;
	lexer->tokens = ft_calloc(capacity, sizeof(t_token));
}

t_lexer		*malloc_lexer(size_t capacity)
{
	t_lexer	*result;

	result = malloc(sizeof(t_lexer));
	if (!result)
		return (NULL);
	create_lexer(result, capacity);
	return (result);
}

void		destroy_lexer(t_lexer lexer)
{
	lexer.size = 0;
	lexer.capacity = 0;
	if (lexer.tokens)
		free(lexer.tokens);
}

void		free_lexer(t_lexer *to_free)
{
	if (to_free)
	{
		destroy_lexer(*to_free);
		free(to_free);
	}
}
