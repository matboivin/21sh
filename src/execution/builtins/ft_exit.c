/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:03:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 18:25:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_num.h"
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_builtins.h"

/*
** Recoded builtin exit() without any options
**
** exit [n]
**    Exits the shell with a status of n.  If n is omitted, the exit status
**    is that of the last command executed.
**
** n: An integer in the range 0 - 255
** Out of range exit values can result in unexpected exit codes. An exit value
** greater than 255 returns an exit code modulo 256.
** For example, exit 3809 gives an exit code of 225 (3809 % 256 = 225).
*/

static int	check_args(int argc, char *cmd_name, char *n)
{
	if (!ft_isnumeric(n))
	{
		g_status = INCORRECT_USAGE;
		print_error(3, cmd_name, n, "numeric argument required");
		return (1);
	}
	if (argc > 2)
	{
		g_status = EXIT_FAILURE;
		print_error(2, cmd_name, "too many arguments");
		return (1);
	}
	return (0);
}

static void	get_exit_status(char *str_repr)
{
	int		n;

	n = ft_atoi(str_repr);
	if (n < 0)
		g_status = MAX_EXIT_VALUE;
	else if (n > MAX_EXIT_VALUE)
		g_status = n % 256;
	else
		g_status = n;
}

// TODO: exit shell

void		ft_exit(int argc, char **argv)
{
	ft_printf("exit\n");
	if (argc > DEFAULT_ARGC)
	{
		if (!check_args(argc, argv[CMD_NAME], argv[FIRST_PARAM]))
			get_exit_status(argv[FIRST_PARAM]);
	}
}
