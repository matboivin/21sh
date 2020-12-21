/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/21 23:48:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_utils.h"

/*
** Print error messages
*/

void	handle_syntax_error(const char *token)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO,
		"%s: syntax error near unexpected token `%s'\n",
		ft_getenv("SHELL_NAME"),
		token);
}

void	handle_matching_error(char c)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO,
		"%s: unexpected EOF while looking for matching `%c'\n",
		ft_getenv("SHELL_NAME"),
		c);
}

void	handle_cmd_not_found(char *filename)
{
	g_status = CMD_NO_FOUND;
	print_error(filename, "command not found");
}

void	print_errno(char *target)
{
	print_error(target, strerror(errno));
}

void	print_builtin_error(char *cmd_name, char *target)
{
	ft_dprintf(
		STDERR_FILENO,
		"%s: %s: %s: %s\n",
		ft_getenv("SHELL_NAME"), cmd_name, target, strerror(errno));
}

void	print_error(char *target, const char *msg)
{
	ft_dprintf(
		STDERR_FILENO, "%s: %s: %s\n", ft_getenv("SHELL_NAME"), target, msg);
}
