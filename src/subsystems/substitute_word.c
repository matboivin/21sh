/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:10:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/09 16:54:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_ctype.h"
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function substitutes the variable name by its value
*/

static int	check_name_format(int c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*get_var_value(char *data, size_t *i)
{
	char	*key;
	char	*value;
	size_t	key_len;

	key = NULL;
	value = NULL;
	key_len = 0;
	while (data[*i + key_len] && check_name_format(data[*i + key_len]))
		key_len++;
	if (key_len)
	{
		key = ft_substr(data, *i, key_len);
		value = ft_getenv(key);
		ft_strdel(&key);
		if (value)
			*i += key_len;
	}
	return (value);
}

static void	handle_dollar(char **result, char *data, size_t *start, size_t *i)
{
	char	*prefix;
	char	*var_value;
	size_t	len;

	len = *i - *start;
	(*i)++;
	prefix = NULL;
	var_value = get_var_value(data, i);
	if (!var_value)
		return ;
	prefix = ft_strjoindelone(ft_substr(data, *start, len), var_value);
	if (!prefix)
		return ;
	*result = ft_strjoindel(*result, prefix);
	*start = *i;
}

char		*substitute_word(char *data)
{
	char	*result;
	size_t	start;
	size_t	i;

	if ((*data == STRONG_QUOTE) || (!ft_strchr(data, DOLLAR_SIGN)))
		return (NULL);
	result = NULL;
	start = 0;
	i = 0;
	while (data && data[i])
	{
		if (data[i] == DOLLAR_SIGN)
			handle_dollar(&result, data, &start, &i);
		else
			i++;
	}
	if ((i - start) > 0)
		result = ft_strjoindel(result, ft_substr(data, start, (i - start)));
	return (result);
}
