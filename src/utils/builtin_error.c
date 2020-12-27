/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/27 18:08:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_printf.h"
#include "sh_utils.h"

/*
** Print error messages for builtins
*/

int		handle_arg_err(char *cmd_name)
{
	g_status = EXIT_FAILURE;
	print_error(2, cmd_name, "too many arguments");
	return (EXIT_FAILURE);
}

int		handle_invalid_id(char *cmd_name, char *var_name)
{
	g_status = EXIT_FAILURE;
	print_error(3, cmd_name, var_name, "not a valid identifier");
	return (EXIT_FAILURE);
}

int		handle_env_not_set(char *cmd_name, char *var_name)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO, "%s: %s: %s not set\n", SHELL_NAME, cmd_name, var_name);
	return (EXIT_FAILURE);
}
