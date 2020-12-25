/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:03:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/25 22:10:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_num.h"
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_subsystems.h"
#include "sh_builtins.h"

/*
** Recoded builtin exit() without any options
*/

/*
** This function checks if the parameter is numeric (the exit value) and if
** there is no more than one parameter
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
		return (handle_arg_err(cmd_name));
	return (0);
}

/*
** Exit value is an integer in the range (0, 255)
** 255 = MAX_EXIT_VALUE
** 256 = MAX_STATES
**
** A value greater than 255 returns:
**   exit code % 256
** A negative value (lesser than 0) returns:
**   exit code % 256 + 256 (so it becomes positive)
*/

static void	get_exit_status(char *str_repr)
{
	int		n;

	n = ft_atoi(str_repr);
	if (n > MAX_EXIT_VALUE)
		g_status = n % MAX_STATES;
	else if (n < 0)
		g_status = n % MAX_STATES + MAX_STATES;
	else
		g_status = n;
}

/*
** exit [n]
**     Exits the shell with a status of n (an integer in the range (0, 255)).
**     If n is omitted, the exit status is that of the last command executed.
*/

int			exit_builtin(int argc, char **argv)
{
	ft_printf("exit\n");
	if (argc > DEFAULT_ARGC)
	{
		if (!check_args(argc, argv[CMD_NAME], argv[FIRST_PARAM]))
			get_exit_status(argv[FIRST_PARAM]);
	}
	jump_to_top_level();
	return (0);
}
