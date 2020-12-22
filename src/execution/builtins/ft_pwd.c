/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 00:55:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <limits.h>
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin pwd() without any options
**
** If no option is specified, -P is assumed
*/

void		ft_pwd(int argc, char **argv)
{
	char	*path;
	char	buf[PATH_MAX];

	path = NULL;
	if (argc != DEFAULT_ARGC)
	{
		g_status = INCORRECT_USAGE;
		print_error(argv[CMD_NAME], "no option must be specified");
	}
	else
	{
		path = getcwd(buf, PATH_MAX);
		if (!path)
			print_error(argv[CMD_NAME], strerror(errno));
		else
			ft_printf("%s\n", path);
	}
}
