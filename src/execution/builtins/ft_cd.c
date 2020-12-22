/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:34:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 01:07:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include "libft_printf.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin cd() with only a relative or absolute path
*/

// TODO: fix

void		ft_cd(int argc, char **argv)
{
	char	*oldpwd_value;
	int		new_dir;

	oldpwd_value = getcwd(NULL, PATH_MAX);
	if (argc > 2)
	{
		g_status = EXIT_FAILURE;
		print_error(argv[CMD_NAME], "too many arguments");
		return ;
	}
	if (argc == DEFAULT_ARGC)
		new_dir = chdir(ft_getenv("HOME"));
	else
	{
		ft_printf("%s\n", argv[1]);
		new_dir = chdir(argv[1]);
	}
	if (new_dir == FAIL_RET)
	{
		print_builtin_error(argv[CMD_NAME], argv[1], strerror(errno));
		return ;
	}
	ft_setenv("OLDPWD", oldpwd_value, true);
	ft_setenv("PWD", getcwd(NULL, 0), true);
}
