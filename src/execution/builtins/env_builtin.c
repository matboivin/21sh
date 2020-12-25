/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:50:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 00:38:02 by mboivin          ###   ########.fr       */
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

	if (argc != NO_ARGS)
		return (handle_arg_err(argv[CMD_NAME]));
	write_ret = ft_printenv();
	if (write_ret == FAIL_RET)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
