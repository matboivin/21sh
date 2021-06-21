/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:17:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/21 19:39:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"
#include "libft_str.h"
#include "shell.h"
#include "utils.h"

/*
 * The shell passes the environment to other commands
 */

char	**g_shell_environment;

/*
 * If '--help' option, prints usage
 */

void	put_shell_usage(char *argv0)
{
	printf("Usage: %s [long option] ...\n\n\
		\rlong options:\n\
		\r        --help\n",
		argv0); // tmp
}

void	exit_shell(t_shell **to_free)
{
	if ((*to_free)->shell_name)
		ft_strdel(&(*to_free)->shell_name);
	if (to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

t_shell	*init_shell(void)
{
	t_shell	*result;

	result = NULL;
	result = malloc(sizeof(*result));
	if (!result)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	result->interactive_shell = 1;
	result->login_shell = 0;
	result->shell_name = NULL;
	return (result);
}

static void	set_shell_name(t_shell *shell, char *argv0)
{
	shell->shell_name = ft_strdup(get_base_pathname(argv0));
	if (!shell->shell_name)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
}

void	set_shell(t_shell *shell, int argc, char **argv, char **envp)
{
	(void)argc;
	g_shell_environment = envp;
	set_shell_name(shell, argv[0]);
}
