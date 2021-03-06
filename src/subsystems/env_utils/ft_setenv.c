/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:14:01 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/13 12:11:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "libft_str.h"
#include "sh_env.h"

/*
** This function adds a new definition to the environment
** If value is an empty string, the variable is set to an empty string.
**
** key: Name of the variable
** new_value: Value of the variable
** replace: if true: Always replace the variable.
**          if false: If the new entry already exists, nothing happens.
**                    Otherwise, the entry is replaced by the new one.
**
** returns: 0 on success
**          -1 on error
*/

static int	check_arg_fmt(char *key, char *new_value)
{
	if (
		!g_env || !key || !new_value
		|| !ft_strcmp(key, EMPTY_STR) || ft_strchr(key, ENV_VAR_SEP))
		return (0);
	return (1);
}

int			ft_setenv(char *key, char *new_value, bool replace)
{
	int		to_set;

	if (!check_arg_fmt(key, new_value))
		return (FAIL_RET);
	to_set = ft_findenv(key);
	if ((to_set != FAIL_RET) && replace)
	{
		if (!ft_strcmp(new_value, EMPTY_STR))
			g_env[to_set] = ft_strreplace(g_env[to_set], EMPTY_STR);
		else
		{
			ft_strdel(&g_env[to_set]);
			g_env[to_set] = ft_join_n_str(3, key, "=", new_value);
			if (!g_env[to_set])
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
		}
		return (0);
	}
	return (FAIL_RET);
}
