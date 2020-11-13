/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:04:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 22:59:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_mem.h"
#include "sh_lexer.h"

/*
** This function doubles the capacity of the lexer
*/

static t_token	**dup_lexer(t_token **to_free, int max, size_t count)
{
	t_token		**result;
	int			i;

	result = ft_calloc((count + 1), sizeof(t_token *));
	if (!result)
		return (NULL);
	i = 0;
	if (to_free && max)
	{
		while (to_free[i] && i < max)
		{
			result[i] = malloc_token(
				to_free[i]->content, to_free[i]->len, to_free[i]->type);
			i++;
		}
		delete_tokens(to_free, max);
	}
	return (result);
}

void			increase_lexer(t_lexer *lexer)
{
	lexer->capacity *= 2;
	lexer->tokens = dup_lexer(lexer->tokens, lexer->size, lexer->capacity);
}
