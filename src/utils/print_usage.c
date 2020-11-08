/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:50:46 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 18:04:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "ft_sh.h"

void	print_usage(void)
{
	ft_dprintf(STDERR_FILENO, "Usage: ./ft_sh\n");
	exit(EXIT_SUCCESS);
}
