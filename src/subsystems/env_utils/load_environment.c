/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:09:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/08 19:35:58 by mboivin          ###   ########.fr       */
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
	size_t	start;
	size_t	len;

	start = 0;
	len = ft_strlen(argv0);
	if (ft_strcmp(argv0, "./"))
		start = 2;
	len = ft_strlen(argv0) - start;
	return (ft_substr(argv0, start, len));
}

void		set_shell_name(char *argv0)
{
	char	*shell_name;
	char	*shell_value;

	shell_value = get_shell_name(argv0);
	if (shell_value)
	{
		shell_name = ft_join_n_str(3, "SHELL_NAME", "=", shell_value);
		if (shell_name)
			ft_putenv(shell_name);
		ft_strdel(&shell_value);
	}
	else
		ft_setenv("SHELL_NAME", DEFAULT_SHELL_NAME, true);
}

void		load_environment(char **envp, char *argv0)
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
	set_shell_name(argv0);
}
