/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:50:46 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/04 13:34:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_utils.h"

/*
** This function prints the usage message
*/

void	print_usage(char *argv0)
{
	ft_dprintf(STDERR_FILENO, "Usage: %s\n", argv0);
	exit(EXIT_SUCCESS);
}
