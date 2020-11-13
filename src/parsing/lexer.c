/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 23:30:43 by mboivin          ###   ########.fr       */
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
	delete_tokens(to_destroy.tokens, to_destroy.size);
}

void		free_lexer(t_lexer *to_free)
{
	if (to_free)
	{
		destroy_lexer(*to_free);
		free(to_free);
	}
}

void		print_lexer(t_lexer *lexer)
{
	size_t	i;

	i = 0;
	ft_printf("----------- LEXER -----------\n");
	ft_printf("size: %ld\n", lexer->size);
	ft_printf("capacity: %ld\n", lexer->capacity);
	ft_printf("tokens:\n");
	while (i < lexer->size)
	{
		ft_printf(
			"  %ld: %s | len: %ld\n",
			i, lexer->tokens[i]->content, lexer->tokens[i]->len);
		i++;
	}
}
