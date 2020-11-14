/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 22:00:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_utils.h"

/*
** Syntax errors
*/

void	print_syntax_error(const char *token)
{
	ft_dprintf(
		STDERR_FILENO,
		"%s: syntax error near unexpected token `%s'\n",
		SHELL_NAME,
		token);
}

void	print_match_error(char c)
{
	ft_dprintf(
		STDERR_FILENO,
		"%s: unexpected EOF while looking for matching `%c'\n",
		SHELL_NAME,
		c);
}

// void		exit_error(char *target, t_shctrl *ft_sh)
// {
// 	char	*msg;

// 	msg = (char *)strerror(errno);
// 	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", SHELL_NAME, target, msg);
// 	exit_ft_sh(EXIT_FAILURE, ft_sh);
// }
