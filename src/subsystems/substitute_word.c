/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:10:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/07 19:02:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_ctype.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function substitutes the variable name by its value
*/

static int	check_name(int c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*get_prefix(char *data, int prefix_len)
{
	if (prefix_len > 0)
		return (ft_substr(data, 0, prefix_len));
	return (ft_strdup(""));
}

static char	*get_suffix(char *data, int suffix_start)
{
	size_t	len;

	len = ft_strlen(data) - suffix_start;
	if (len > 0)
		return (ft_substr(data, suffix_start, len));
	return (ft_strdup(""));
}

static char	*get_var_value(char *data, int *prefix_len, int *suffix_start)
{
	char	*var_name;
	char	*var_value;
	size_t	start;
	size_t	len;

	*prefix_len = 0;
	len = 0;
	while (data[*prefix_len] && data[*prefix_len] != DOLLAR_SIGN)
		(*prefix_len)++;
	start = *prefix_len + 1;
	while (data[start + len] && check_name(data[start + len]))
		len++;
	if (len > 0)
	{
		*suffix_start = start + len;
		var_name = ft_substr(data, start, len);
		var_value = ft_getenv(var_name);
		ft_strdel(&var_name);
		if (var_value)
			return (var_value);
	}
	return (NULL);
}

static char	*replace_name(
	char *data, char *value, int prefix_len, int suffix_start)
{
	char	*result;
	char	*prefix;
	char	*suffix;

	result = NULL;
	prefix = get_prefix(data, prefix_len);
	suffix = get_suffix(data, suffix_start);
	result = ft_join_n_str(3, prefix, value, suffix);
	ft_strdel(&prefix);
	ft_strdel(&suffix);
	if (result)
		return (result);
	return (NULL);
}

// TODO: Handle many $ in one string

char		*substitute_word(char *data)
{
	char	*new_word;
	char	*var_value;
	int		prefix_len;
	int		suffix_start;

	new_word = NULL;
	if ((*data == STRONG_QUOTE) || (!ft_strchr(data, DOLLAR_SIGN)))
		return (NULL);
	var_value = get_var_value(data, &prefix_len, &suffix_start);
	if (var_value)
	{
		new_word = replace_name(data, var_value, prefix_len, suffix_start);
		if (new_word)
			return (new_word);
	}
	return (NULL);
}
