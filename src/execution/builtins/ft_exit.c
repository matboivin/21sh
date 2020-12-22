/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:03:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 14:44:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_ctype.h"
#include "libft_conv.h"
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin exit() without any options
*/

// TODO: exit shell

void	ft_exit(int argc, char **argv)
{
	ft_printf("exit\n");
	if (argc > DEFAULT_ARGC)
	{
		if (!ft_isnumeric(argv[FIRST_PARAM]))
		{
			g_status = INCORRECT_USAGE;
			print_builtin_error(
				argv[CMD_NAME], argv[FIRST_PARAM], "numeric argument required");
		}
		else if (argc > 2)
		{
			g_status = EXIT_FAILURE;
			print_error(argv[CMD_NAME], "too many arguments");
		}
		else
			g_status = ft_atoi(argv[FIRST_PARAM]);
	}
}
