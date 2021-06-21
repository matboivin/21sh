/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:16 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/21 17:47:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_builtins.h"

/*
** This functions displays all exported variables
**
** If no names are given, or if the -p option is supplied, a list of names of
** all exported variables is printed.
**
** Format: declare -x VAR
** declare -x: Mark names for export via the environment
*/

static char	**sort_export_list(void)
{
	char	**result;
	size_t	i;
	size_t	j;

	i = 0;
	result = dup_environment(ft_str_arr_len(g_env), false);
	if (!result)
	{
		print_errno("malloc");
		return (NULL);
	}
	while (result[i])
	{
		j = 0;
		while (result[j])
		{
			if (ft_strcmp(result[i], result[j]) < 0)
				ft_strswap(&(result[j]), &(result[i]));
			j++;
		}
		i++;
	}
	return (result);
}

// Write error not handled

static int	print_key_value(char *sorted_env)
{
	int		i;
	size_t	len;
	char	*value;

	value = NULL;
	if (!sorted_env)
		return (FAIL_RET);
	i = get_env_len(sorted_env);
	len = ft_strlen(sorted_env) - i;
	value = ft_substr(sorted_env, (i + 1), len);
	printf("declare -x %.*s=\"%s\"\n", i, sorted_env, value);
	ft_strdel(&value);
	return (EXIT_SUCCESS);
}

static int	print_env_var(char **sorted_env)
{
	size_t	i;

	i = 0;
	if (sorted_env && sorted_env[i])
	{
		while (sorted_env[i])
		{
			if (!ft_strchr(sorted_env[i], ENV_VAR_SEP))
				printf("declare -x %s\n", sorted_env[i]);
			else if (ft_strncmp(sorted_env[i], "_=", 2))
				print_key_value(sorted_env[i]);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}

int			display_export(void)
{
	char	**sorted_env;
	int		ret;

	sorted_env = NULL;
	sorted_env = sort_export_list();
	if (sorted_env)
	{
		ret = print_env_var(sorted_env);
		ft_str_arr_del(sorted_env);
		if (ret != FAIL_RET)
			return (EXIT_SUCCESS);
		else
			print_errno("write error");
	}
	return (EXIT_FAILURE);
}
