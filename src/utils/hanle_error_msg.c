/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanle_error_msg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/25 18:55:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_printf.h"
#include "sh_utils.h"

/*
** Print error messages
*/

void		handle_syntax_error(const char *token)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO,
		"%s: syntax error near unexpected token `%s'\n",
		SHELL_NAME,
		token);
}

void		handle_matching_error(char c)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO,
		"%s: unexpected EOF while looking for matching `%c'\n",
		SHELL_NAME,
		c);
}

void		handle_cmd_not_found(char *filename)
{
	g_status = CMD_NO_FOUND;
	print_error(2, filename, "command not found");
}

int			handle_invalid_id(char *cmd_name, char *var_name)
{
	g_status = EXIT_FAILURE;
	print_error(3, cmd_name, var_name, "not a valid identifier");
	return (EXIT_FAILURE);
}
