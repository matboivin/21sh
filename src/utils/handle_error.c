/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/15 22:34:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include "libft_printf.h"
#include "wandre_mode.h"
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
		SHELL_NAME,
		token);
#ifdef WANDRE_MODE
	wandroulette(NULL);
#endif /* WANDRE_MODE */
}

void	handle_matching_error(char c)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO,
		"%s: unexpected EOF while looking for matching `%c'\n",
		SHELL_NAME,
		c);
#ifdef WANDRE_MODE
	wandroulette(NULL);
#endif /* WANDRE_MODE */
}

void	handle_cmd_not_found(char *filename)
{
	g_status = CMD_NO_FOUND;
	print_error(2, filename, "command not found");
#ifdef WANDRE_MODE
	wandroulette(filename);
#endif /* WANDRE_MODE */
}
