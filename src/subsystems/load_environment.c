/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:09:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/06 18:11:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_env.h"

char		**g_env;

/*
** This function loads the environment from envp
**
** envp: The environment represented as an array of strings
*/

static char	*get_shell_name(char *argv0)
{
	size_t	len;

	if (ft_strcmp(argv0, "./"))
	{
		len = ft_strlen(argv0) - 2;
		return (ft_substr(argv0, 2, len));
	}
	return (NULL);
}

void		load_environment(char **envp, char *argv0)
{
	size_t	i;
	size_t	count;
	char	*shell_name;

	count = ft_str_arr_len(envp);
	g_env = ft_calloc((count + 1), sizeof(char *));
	if (!g_env)
		exit(EXIT_FAILURE);
	shell_name = NULL;
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
	shell_name = get_shell_name(argv0);
	if (shell_name)
	{
		ft_setenv("SHELL", shell_name, true);
		ft_strdel(&shell_name);
	}
}
