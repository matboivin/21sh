/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 18:16:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdarg.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_utils.h"

/*
** Print error messages
*/

void		print_errno(char *target)
{
	g_status = EXIT_FAILURE;
#ifdef DEBUG
	ft_printf("errno %d %s\n", errno, strerror(errno));
#endif /* DEBUG */
	if (errno == EACCES)
	{
		if (is_directory(target))
			errno = EISDIR;
	}
	print_error(2, target, strerror(errno));
}

void		print_error(int count, ...)
{
	va_list	ap;

	if (count < 1)
		return ;
	ft_dprintf(STDERR_FILENO, "%s", SHELL_NAME);
	va_start(ap, count);
	while (count > 0)
	{
		ft_dprintf(STDERR_FILENO, ": %s", va_arg(ap, char *));
		count--;
	}
	va_end(ap);
	ft_dprintf(STDERR_FILENO, "\n");
}
