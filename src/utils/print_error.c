/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/06 18:23:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_utils.h"

/*
** Syntax errors
*/

void	print_syntax_error(const char *token)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO,
		"%s: syntax error near unexpected token `%s'\n",
		ft_getenv("SHELL"),
		token);
}

void	print_matching_error(char c)
{
	g_status = INCORRECT_USAGE;
	ft_dprintf(
		STDERR_FILENO,
		"%s: unexpected EOF while looking for matching `%c'\n",
		ft_getenv("SHELL"),
		c);
}

// void		exit_error(char *target, t_shctrl *ft_sh)
// {
// 	char	*msg;

// 	msg = (char *)strerror(errno);
// 	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", ft_getenv("SHELL"), target, msg);
// 	exit_shell(EXIT_FAILURE, ft_sh);
// }
