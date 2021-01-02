/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:10:12 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 13:16:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_ctype.h"
#include "libft_conv.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function checks an environment variable name format:
** underscores, digits, and ASCII letters, and that begin with a non-digit
** and returns its length
*/

static size_t	get_var_len(char *s)
{
	size_t		i;

	i = 0;
	if (ft_isdigit(s[i]))
		return (1);
	while ((ft_isalnum(s[i])) || (s[i] == '_'))
		i++;
	return (i);
}

/*
** This function cuts the environment variable name after a dollar sign
*/

static char		*get_var_name(char *data, size_t *i)
{
	char		*key;
	size_t		key_len;
	size_t		start;

	key = NULL;
	key_len = 0;
	start = *i + 1;
	if (data[start + key_len] == '?')
		key_len++;
	else
		key_len = get_var_len(data + start);
	if (key_len)
	{
		key = ft_substr(data, start, key_len);
		*i += key_len;
		return (key);
	}
	return (NULL);
}

/*
** This function returns the value corresponding to a variable name parameter
** If variable is $?, returns the previous command exit status
*/

static char		*get_var_value(char *var_name)
{
	char		*result;

	result = NULL;
	if (!ft_strcmp(var_name, "?"))
		result = ft_itoa(g_status, result, DEC_BASE);
	else
	{
		if (ft_findenv(var_name) != FAIL_RET)
			result = ft_strdup(ft_getenv(var_name));
		else
			result = ft_strdup("");
	}
	return (result);
}

/*
** This function substitutes environment variable prefixed by a dollar sign by
** their values
*/

void			substitute_var(char **result, char *tok_word, size_t *i)
{
	char		*var_name;
	char		*var_value;

	var_name = NULL;
	var_value = NULL;
	if (is_quote(tok_word[*i + 1]))
	{
		(*i)++;
		return ;
	}
	var_name = get_var_name(tok_word, i);
	if (var_name)
	{
		if (is_valid_identifier(var_name))
		{
			var_value = get_var_value(var_name);
			if (var_value)
				*result = ft_strjoindel(*result, var_value);
		}
		ft_strdel(&var_name);
	}
	else
		*result = ft_append_char(*result, tok_word + *i, true);
}
