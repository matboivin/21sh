/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:34:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 00:29:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
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

static int	update_oldpwd(void)
{
	if (ft_setenv("OLDPWD", ft_getenv("PWD"), true) != FAIL_RET)
		return (0);
	return (FAIL_RET);
}

static int	update_pwd(char *cmd_name)
{
	char	cwd[PATH_MAX];

	if (update_oldpwd() != FAIL_RET)
	{
		if (getcwd(cwd, PATH_MAX) && (ft_setenv("PWD", cwd, true) != FAIL_RET))
			return (0);
	}
	print_errno(cmd_name);
	return (EXIT_FAILURE);
}

static int	change_dir(int argc, char *dir)
{
	if (argc == DEFAULT_ARGC)
		return (chdir(ft_getenv("HOME")));
	return (chdir(dir));
}

int			cd_builtin(int argc, char **argv)
{
	int		new_dir;

	if (argc > 2)
		return (handle_arg_err(argv[CMD_NAME]));
	new_dir = change_dir(argc, argv[1]);
	if (new_dir == FAIL_RET)
	{
		print_error(3, argv[CMD_NAME], argv[1], strerror(errno));
		return (EXIT_FAILURE);
	}
	return (update_pwd(argv[CMD_NAME]));
}
