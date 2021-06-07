/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:40:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
	dprintf(STDERR_FILENO, "%s: %s: `%s': not a valid identifier\n", SHELL_NAME, cmd_name, var_name);
	return (EXIT_FAILURE);
}

int		handle_invalid_opt(char *cmd_name, char *opt)
{
	g_status = INCORRECT_USAGE;
	dprintf(STDERR_FILENO, "%s: %s: %.2s: invalid option\n", SHELL_NAME, cmd_name, opt);
	return (EXIT_FAILURE);
}

int		handle_env_not_set(char *cmd_name, char *var_name)
{
	g_status = INCORRECT_USAGE;
	dprintf(STDERR_FILENO, "%s: %s: %s not set\n", SHELL_NAME, cmd_name, var_name);
	return (EXIT_FAILURE);
}

void	print_builtin_usage(char *cmd_name, char *msg)
{
	if (!cmd_name || !msg)
		return ;
	dprintf(STDERR_FILENO, "%s: usage: %s\n", cmd_name, msg);
}
