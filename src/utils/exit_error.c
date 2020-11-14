/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:00:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
#include "sh_utils.h"

/*
** This function prints an error message, frees the allocated memory and exits
** with 1
*/

void		exit_error(char *target, t_shctrl *ft_sh)
{
	char	*msg;

	msg = (char *)strerror(errno);
	ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", SHELL_NAME, target, msg);
	exit_ft_sh(EXIT_FAILURE, ft_sh);
}
