/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:09:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 23:20:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_conv.h"
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_env.h"

char		**g_env;

/*
** This function loads the environment from envp
**
** envp: The environment represented as an array of strings
*/

static void	increment_count(void)
{
	char	*new_val;
	char	*str_repr;
	int		count;

	new_val = NULL;
	str_repr = NULL;
	count = 0;
	str_repr = ft_getenv("SHLVL");
	if (str_repr)
	{
		count = ft_atoi(str_repr) + 1;
		new_val = ft_itoa(count, new_val, DEC_BASE);
		ft_setenv("SHLVL", new_val, true);
		ft_strdel(&new_val);
	}
}

void		load_environment(char **envp)
{
	size_t	i;
	size_t	count;

	count = ft_str_arr_len(envp);
	g_env = ft_calloc((count + 1), sizeof(char *));
	if (!g_env)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < count)
	{
		if (ft_strcmp(envp[i], EMPTY_STR))
		{
			g_env[i] = ft_strdup(envp[i]);
			if (!g_env[i])
				exit(EXIT_FAILURE);
		}
		i++;
	}
	increment_count();
}
