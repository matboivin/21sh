/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:10:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/09 18:25:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_ctype.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

static int	check_name_format(int c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*get_var_name(char *data, size_t *i)
{
	char	*key;
	size_t	key_len;

	key = NULL;
	key_len = 0;
	while (data[*i + key_len] && check_name_format(data[*i + key_len]))
		key_len++;
	if (key_len)
	{
		key = ft_substr(data, *i, key_len);
		*i += key_len;
		return (key);
	}
	return (NULL);
}

static void	handle_dollar(char **result, char *data, size_t *start, size_t *i)
{
	char	*prefix;
	char	*var_name;
	char	*var_value;
	size_t	len;

	len = *i - *start;
	(*i)++;
	prefix = NULL;
	var_name = get_var_name(data, i);
	if (!var_name)
		return ;
	var_value = ft_getenv(var_name);
	if (var_value)
		prefix = ft_strjoindelone(ft_substr(data, *start, len), var_value);
	else
		prefix = ft_substr(data, *start, len);
	if (prefix)
		*result = ft_strjoindel(*result, prefix);
	*start = *i;
	ft_strdel(&var_name);
}

/*
** This function substitutes the variable names by their values
*/

void		substitute_word(char **data)
{
	char	*result;
	char	*s;
	size_t	start;
	size_t	i;

	if ((**data == STRONG_QUOTE) || (!ft_strchr(*data, DOLLAR_SIGN)))
		return ;
	s = *data;
	result = NULL;
	start = 0;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == DOLLAR_SIGN)
			handle_dollar(&result, s, &start, &i);
		else
			i++;
	}
	if ((i - start) > 0)
		result = ft_strjoindel(result, ft_substr(s, start, (i - start)));
	if (result)
		*data = ft_strreplace(*data, result);
	ft_strdel(&result);
}
