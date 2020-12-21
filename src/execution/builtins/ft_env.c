/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:50:53 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/21 23:35:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin env() with no options and no arguments
**
** If no command name is specified following the environment specifications,
** the resulting environment is printed. This is like specifying the printenv
** program.
*/

void	ft_env(int argc, char **argv)
{
	if (argc != DEFAULT_ARGC)
	{
		g_status = INCORRECT_USAGE;
		print_error(argv[CMD_NAME], "no option must be specified");
	}
	else
		ft_printenv();
}
