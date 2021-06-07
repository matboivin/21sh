/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:50 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:45:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin pwd() without any options
**
** pwd
**     Print the name of the current working directory.
**
** returns: 0
**          non-zero if an invalid option is given or the current directory
**          cannot be read
*/

int			pwd_builtin(int argc, char **argv)
{
	char	cwd[PATH_MAX];

	if (argc != NO_ARGS)
	{
		if (argv[FIRST_PARAM][0] == '-')
		{
			handle_invalid_opt(argv[CMD_NAME], argv[FIRST_PARAM]);
			print_builtin_usage("pwd", "pwd");
			return (EXIT_FAILURE);
		}
	}
	if (!getcwd(cwd, PATH_MAX))
	{
		print_errno(argv[CMD_NAME]);
		return (EXIT_FAILURE);
	}
	printf("%s\n", cwd);
	return (0);
}
