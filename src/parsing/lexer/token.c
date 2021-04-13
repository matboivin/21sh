/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/13 12:11:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_lexer.h"

/*
** Token
**
** create_token()   :  Constructor
** malloc_token()   :  Malloc function
** free_token()     :  Free function
** delete_tokens()  :  Free all tokens in lexer
*/

t_token		create_token(const char *s, size_t p_len, t_tok_type p_type)
{
	t_token	result;

	result.len = p_len;
	result.type = p_type;
	result.value = ft_strnew(p_len);
	ft_strlcpy(result.value, s, (p_len + 1));
	return (result);
}

t_token		*malloc_token(const char *s, size_t p_len, t_tok_type p_type)
{
	t_token	*result;

	result = malloc(sizeof(t_token));
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	*result = create_token(s, p_len, p_type);
	return (result);
}

void		free_token(t_token **to_free)
{
	if (to_free)
	{
		ft_strdel(&(*to_free)->value);
		free(*to_free);
		*to_free = NULL;
	}
}

void		delete_tokens(t_token **tokens, size_t size)
{
	size_t	i;

	i = 0;
	if (tokens && size)
	{
		while (tokens && tokens[i] && i < size)
			free_token(&tokens[i++]);
	}
	if (tokens)
	{
		free(tokens);
		tokens = NULL;
	}
}
