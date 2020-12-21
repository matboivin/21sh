/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:34:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/21 23:54:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft_str.h"
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin cd() with only a relative or absolute path
*/

int			ft_cd(int argc, char **argv)
{
	int		new_dir;
	t_env	*directory;
	char	*oldpwd_value;

	oldpwd_value = getcwd(NULL, 0);
	directory = g_env;
	if (argc > 2)
	{
		g_status = EXIT_FAILURE;
		print_error(argv[CMD_NAME], "too many arguments");
		return (EXIT_FAILURE);
	}
	if (argc == DEFAULT_ARGC)
		new_dir = chdir(ft_getenv("HOME"));
	else
		new_dir = chdir(argv[1]);
	if (new_dir == FAIL_RET)
	{
		print_builtin_error(argv[CMD_NAME], argv[1]);
		return (EXIT_FAILURE);
	}
	ft_setenv("OLDPWD", oldpwd_value, true);
	ft_setenv("PWD", getcwd(NULL, 0), true);
	return (0);
}
