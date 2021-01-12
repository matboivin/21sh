/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/13 00:15:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_subsystems.h"

/*
** The backslash retains its special meaning only when followed by one of the
** following characters: ‘$’, ‘`’, ‘"’, ‘\’, or newline. Within double quotes,
** backslashes that are followed by one of these characters are removed.
** Backslashes preceding characters without a special meaning are left
** unmodified. A double quote may be quoted within double quotes by preceding
** it with a backslash.
*/

static bool	is_followed_by_special(char *tok_word, size_t i)
{
	i++;
	if (tok_word[i])
	{
		return ((tok_word[i] == DOLLAR_SIGN) || (tok_word[i] == STRONG_QUOTE)
			|| (tok_word[i] == WEAK_QUOTE) || (tok_word[i] == BACKSLASH));
	}
	return (false);
}

void		remove_backslash(char **result, char *tok_word, size_t *i, bool check_special)
{
	if (check_special)
	{
		if (is_followed_by_special(tok_word, *i))
			(*i)++;
	}
	else
		(*i)++;
	*result = ft_append_char(*result, tok_word + *i, true);
}
