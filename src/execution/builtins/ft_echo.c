/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:55:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 00:57:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "libft_io.h"
#include "sh_builtins.h"

/*
** Recoded builtin echo() with option ’-n’
*/

void		ft_echo(int argc, char **argv)
{
	bool	newline;
	int		i;

	i = 1;
	newline = true;
	if (argc > DEFAULT_ARGC)
	{
		if (!ft_strcmp(argv[1], "-n"))
		{
			newline = false;
			i++;
		}
	}
	while (i < argc)
	{
		ft_putstr(argv[i]);
		i++;
		ft_putchar(' ');
	}
	if (newline)
		ft_putchar('\n');
}
