/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:09:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 16:46:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"

char	**g_env;

/*
** This function retrieves the environment from envp
**
** envp: The environment represented as an array of strings
*/

void		init_env(char **envp)
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
}
