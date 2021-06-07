/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:38:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft_mem.h"
#include "libft_str.h"
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
	lexer->pos = DEFAULT_VALUE;
	lexer->size = DEFAULT_SIZE;
	lexer->capacity = p_capacity;
	lexer->input = NULL;
	lexer->tokens = ft_calloc((p_capacity + 1), sizeof(t_token *));
}

t_lexer		*malloc_lexer(size_t p_capacity)
{
	t_lexer	*result = NULL;

	result = malloc(sizeof(t_lexer));
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	create_lexer(result, p_capacity);
	return (result);
}

void		destroy_lexer(t_lexer to_destroy)
{
	if (to_destroy.input)
		ft_strdel(&(to_destroy.input));
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
	printf("\n----------- DEBUG: LEXER -----------\n");
	if (lexer)
	{
		printf(
			"size: %ld\ncapacity: %ld\ntokens:\n",
			lexer->size, lexer->capacity);
		while (i < lexer->size)
		{
			printf(
				"  [%ld]\tlen: %ld\t|%s|\n",
				i, lexer->tokens[i]->len, lexer->tokens[i]->value);
			i++;
		}
	}
	else
		printf("Lexer is empty\n");
	printf("------------------------------------\n");
}
