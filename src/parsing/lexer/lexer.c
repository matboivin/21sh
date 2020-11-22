/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/15 19:40:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_mem.h"
#include "libft_printf.h"
#include "sh_lexer.h"

/*
** Lexer: lexical analyzer
**
** create_lexer()   :  Constructor
** malloc_lexer()   :  Malloc function
** destroy_lexer()  :  Destructor
** free_lexer()     :  Free function
*/

void		create_lexer(t_lexer *lexer, size_t p_capacity)
{
	lexer->size = DEFAULT_SIZE;
	lexer->capacity = p_capacity;
	lexer->tokens = ft_calloc((p_capacity + 1), sizeof(t_token *));
}

t_lexer		*malloc_lexer(size_t p_capacity)
{
	t_lexer	*result;

	result = malloc(sizeof(t_lexer));
	if (!result)
		return (NULL);
	create_lexer(result, p_capacity);
	return (result);
}

void		destroy_lexer(t_lexer to_destroy)
{
	if (to_destroy.tokens)
		delete_tokens(to_destroy.tokens, to_destroy.size);
}

void		free_lexer(t_lexer **to_free)
{
	if (to_free)
	{
		destroy_lexer(**to_free);
		free(*to_free);
		*to_free = NULL;
	}
}

void		print_lexer(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	ft_printf("\n----------- DEBUG: LEXER -----------\n");
	if (lexer)
	{
		ft_printf(
			"size: %ld\ncapacity: %ld\ntokens:\n",
			lexer->size, lexer->capacity);
		while (i < lexer->size)
		{
			ft_printf(
				"  %ld -> content: |%s| len: %ld\n",
				i, lexer->tokens[i]->content, lexer->tokens[i]->len);
			i++;
		}
	}
	else
		ft_printf("Lexer is empty\n");
	ft_printf("------------------------------------\n");
}
