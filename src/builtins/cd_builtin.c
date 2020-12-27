/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:34:33 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/27 18:04:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin cd() with only a relative or absolute path
*/

/*
** This function sets former current directory
*/

static int	set_old_pwd(void)
{
	char	*new_var;
	int		ret;

	new_var = NULL;
	if (!ft_getenv("PWD"))
		set_working_dir();
	if (ft_findenv("OLDPWD") != FAIL_RET)
		return (ft_setenv("OLDPWD", ft_getenv("PWD"), true));
	new_var = ft_join_n_str(2, "OLDPWD=", ft_getenv("PWD"));
	if (new_var)
		ret = ft_putenv(new_var);
	ft_strdel(&new_var);
	return (ret);
}

/*
** This function changes working directory to dir and updates the current
** working directory
*/

static int	set_directory(char *cmd_name, char *dir)
{
	if (set_old_pwd() != FAIL_RET)
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
** This function retrieves the dir name to change the working directory
*/

static int	change_to_directory(char *cmd_name, char *dir_name)
{
	char	*path;
	int		ret_val;

	path = NULL;
	ret_val = EXIT_FAILURE;
	if (!ft_getenv(dir_name))
	{
		handle_env_not_set(cmd_name, dir_name);
		return (ret_val);
	}
	path = ft_strdup(ft_getenv(dir_name));
	if (!path)
		return (ret_val);
	ret_val = set_directory(cmd_name, path);
	ft_strdel(&path);
	return (ret_val);
}

/*
** cd [dir]
**     Change the current directory to DIR. The default DIR is the value of the
**     HOME shell variable.
**
** `cd' without arguments is equivalent to `cd $HOME'
** `cd -' is equivalent to `cd $OLDPWD' and the new directory name is echoed to
**   stdout
**
** returns: 0 if the directory is changed
**          non-zero otherwise
*/

int			cd_builtin(int argc, char **argv)
{
	int		ret_val;

	ret_val = 0;
	if (argc > 2)
		return (handle_arg_err(argv[CMD_NAME]));
	if (argc == NO_ARGS)
		ret_val = change_to_directory(argv[CMD_NAME], "HOME");
	else if (!ft_strcmp(argv[FIRST_PARAM], "-"))
	{
		ret_val = change_to_directory(argv[CMD_NAME], "OLDPWD");
		if (!ret_val)
			ft_printf("%s\n", ft_getenv("PWD"));
	}
	else
		ret_val = change_to_directory(argv[CMD_NAME], argv[FIRST_PARAM]);
	return (ret_val);
}
