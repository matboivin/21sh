/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:09:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 22:24:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"

char	**g_env;

/*
** This function retrieves the environment from envp
**
** envp: The environment represented as an array of strings
**
** returns: 0 on success
**          -1 on error
*/

int			init_env(char **envp)
{
	size_t	i;
	size_t	count;

	count = ft_str_arr_len(envp) + 1;
	g_env = ft_calloc(count, sizeof(char *));
	if (!g_env)
		exit(EXIT_FAILURE);
	i = 0;
	while (envp[i])
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	return (0);
}
