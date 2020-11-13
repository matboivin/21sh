/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 21:07:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_lexer.h"

/*
** Token
**
** create_token()   :  Constructor
** malloc_token()   :  Malloc function
** destroy_token()  :  Destructor
** free_token()     :  Free function
** delete_tokens()  :  Free all tokens in lexer
*/

t_token		create_token(char *s, size_t p_len, t_token_type p_type)
{
	t_token	result;

	result.len = p_len;
	result.type = p_type;
	result.content = ft_strnew(p_len);
	ft_strlcpy(result.content, s, (p_len + 1));
	return (result);
}

t_token		*malloc_token(char *s, size_t p_len, t_token_type p_type)
{
	t_token	*result;

	result = malloc(sizeof(t_token));
	if (!result)
		return (NULL);
	*result = create_token(s, p_len, p_type);
	return (result);
}

void		destroy_token(t_token to_destroy)
{
	ft_strdel(&(to_destroy.content));
}

void		free_token(t_token *to_free)
{
	if (to_free)
	{
		destroy_token(*to_free);
		free(to_free);
	}
}

void		delete_tokens(t_token **tokens, size_t capacity)
{
	size_t	i;

	i = 0;
	if (tokens && capacity)
	{
		while (tokens[i] && i < capacity)
			free_token(tokens[i++]);
		free(tokens);
		tokens = NULL;
	}
}
