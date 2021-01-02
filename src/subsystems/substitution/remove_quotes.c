/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:24:50 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 13:04:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_subsystems.h"

/*
** This function removes from the beginning and end of word tokens
*/

static char	*open_strong_quote(char *tok_word, size_t *i)
{
	char	*result;
	size_t	len;

	(*i)++;
	len = 0;
	result = NULL;
	while (tok_word[*i + len] && tok_word[*i + len] != STRONG_QUOTE)
		len++;
	if (!len)
		return (NULL);
	result = ft_substr(tok_word, *i, len);
	*i += len;
	return (result);
}

static char	*open_weak_quote(char *tok_word, size_t *i)
{
	char	*result;
	size_t	len;

	(*i)++;
	len = 0;
	result = NULL;
	while (tok_word[*i + len] && tok_word[*i + len] != WEAK_QUOTE)
	{
		if (tok_word[*i + len] == BACKSLASH)
			remove_backslash(&result, tok_word + *i, &len, true);
		else if (tok_word[*i + len] == DOLLAR_SIGN)
			substitute_var(&result, tok_word + *i, &len);
		else
			result = ft_append_char(result, tok_word + (*i + len), true);
		len++;
	}
	if (!len)
		return (NULL);
	*i += len;
	return (result);
}

void		remove_quotes(char **result, char *tok_word, size_t *i)
{
	char	*substr;

	substr = NULL;
	if (tok_word[*i] == STRONG_QUOTE)
	{
		substr = open_strong_quote(tok_word, i);
		if (substr)
			*result = ft_strjoindel(*result, substr);
	}
	else if (tok_word[*i] == WEAK_QUOTE)
	{
		substr = open_weak_quote(tok_word, i);
		if (substr)
			*result = ft_strjoindel(*result, substr);
	}
}
