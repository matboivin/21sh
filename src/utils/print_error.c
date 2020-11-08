/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 18:04:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "libft_printf.h"
#include "ft_sh.h"

void		print_error(void)
{
	char	*msg;

	msg = (char *)strerror(errno);
	ft_dprintf(STDERR_FILENO, "bash: %s\n", msg); // tmp
	exit(EXIT_FAILURE);
}
