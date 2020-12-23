/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:50:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 15:58:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin env() with no options and no arguments
**
** If no command name is specified following the environment specifications,
** the resulting environment is printed. This is like specifying the printenv
** program.
**
** returns: success
**          non-zero if a write error occurs
*/

int		env_builtin(int argc, char **argv)
{
	int	write_ret;

	if (argc != DEFAULT_ARGC)
	{
		g_status = INCORRECT_USAGE;
		print_error(2, argv[CMD_NAME], "no option must be specified");
		return (TIMEOUT_FAIL);
	}
	write_ret = ft_printenv();
	if (write_ret == FAIL_RET)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
