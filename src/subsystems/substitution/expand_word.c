/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:03:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 13:04:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_subsystems.h"

void		expand_word(char **tok_word)
{
	char	*result;
	size_t	i;
	size_t	len;

	result = NULL;
	i = 0;
	len = ft_strlen(*tok_word);
	while (i < len)
	{
		if (is_quote((*tok_word)[i]))
			remove_quotes(&result, *tok_word, &i);
		else if ((*tok_word)[i] == BACKSLASH)
			remove_backslash(&result, *tok_word, &i, false);
		else if ((*tok_word)[i] == DOLLAR_SIGN)
			substitute_var(&result, *tok_word, &i);
		else
			result = ft_append_char(result, *tok_word + i, true);
		i++;
	}
	if (result)
		*tok_word = ft_strreplace(*tok_word, result);
	ft_strdel(&result);
}
