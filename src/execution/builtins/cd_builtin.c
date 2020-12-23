/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:34:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 15:27:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <limits.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin cd() with only a relative or absolute path
**
** cd [dir]
**     Change the current directory to DIR. The default DIR is the value of the
**     HOME shell variable.
**
** returns: 0 if the directory is changed
**          non-zero otherwise
*/

// TODO: fix

int			cd_builtin(int argc, char **argv)
{
	char	*oldpwd_value;
	int		new_dir;

	oldpwd_value = getcwd(NULL, PATH_MAX);
	if (argc > 2)
	{
		g_status = EXIT_FAILURE;
		print_error(2, argv[CMD_NAME], "too many arguments");
		return (EXIT_FAILURE);
	}
	if (argc == DEFAULT_ARGC)
		new_dir = chdir(ft_getenv("HOME"));
	else
	{
		ft_printf("%s\n", argv[FIRST_PARAM]);
		new_dir = chdir(argv[FIRST_PARAM]);
	}
	if (new_dir == FAIL_RET)
	{
		print_error(3, argv[CMD_NAME], argv[1], strerror(errno));
		return (EXIT_FAILURE);
	}
	ft_setenv("OLDPWD", oldpwd_value, true);
	ft_setenv("PWD", getcwd(NULL, 0), true);
	return (0);
}
