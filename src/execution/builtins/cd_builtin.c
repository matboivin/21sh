/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:34:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 02:16:00 by mboivin          ###   ########.fr       */
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
*/

/*
** This function updates the current working directory if the chdir succeeds
*/

static int	set_working_dir(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		if (ft_setenv("PWD", cwd, true) != FAIL_RET)
			return (0);
	}
	return (FAIL_RET);
}

/*
** This function changes working directory to dir and updates the current
** working directory
*/

static int	change_to_directory(char *cmd_name, char *dir)
{
	char	buf[PATH_MAX];
	char	*oldpwd;

	oldpwd = ft_getenv("PWD");
	if (!oldpwd)
		oldpwd = getcwd(buf, PATH_MAX);
	if (ft_setenv("OLDPWD", oldpwd, true) != FAIL_RET)
	{
		if (chdir(dir) == FAIL_RET)
		{
			print_error(3, cmd_name, dir, strerror(errno));
			return (EXIT_FAILURE);
		}
		else
		{
			if (set_working_dir() != FAIL_RET)
				return (0);
		}
	}
	print_errno(cmd_name);
	return (EXIT_FAILURE);
}

/*
** `cd' without arguments is equivalent to `cd $HOME'
*/

static int	go_to_home(char *cmd_name)
{
	char	*dir_name;

	dir_name = ft_getenv("HOME");
	if (!dir_name)
	{
		print_error(2, cmd_name, "HOME not set");
		return (EXIT_FAILURE);
	}
	return (change_to_directory(cmd_name, dir_name));
}

/*
** `cd -', equivalent to `cd $OLDPWD'
** The new directory name is echoed to stdout
*/

static int	go_back(char *cmd_name)
{
	char	*dir_name;
	int		ret_val;

	ret_val = EXIT_FAILURE;
	dir_name = ft_strdup(ft_getenv("OLDPWD"));
	if (!dir_name)
	{
		print_error(2, cmd_name, "OLDPWD not set");
		return (ret_val);
	}
	ret_val = change_to_directory(cmd_name, dir_name);
	if (!ret_val)
		ft_printf("%s\n", dir_name);
	ft_strdel(&dir_name);
	return (ret_val);
}

/*
** cd [dir]
**     Change the current directory to DIR. The default DIR is the value of the
**     HOME shell variable.
**
** returns: 0 if the directory is changed
**          non-zero otherwise
*/

int			cd_builtin(int argc, char **argv)
{
	if (argc > 2)
		return (handle_arg_err(argv[CMD_NAME]));
	if (argc == NO_ARGS)
		return (go_to_home(argv[CMD_NAME]));
	else if (!ft_strcmp(argv[FIRST_PARAM], "-"))
		return (go_back(argv[CMD_NAME]));
	return (change_to_directory(argv[CMD_NAME], argv[FIRST_PARAM]));
}
