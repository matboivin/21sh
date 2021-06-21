/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:17:02 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/21 19:27:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "builtins.h"
#include "libft_str.h"

/*
 * Prints name and value pairs for all environment variables
 */

int	printenv_builtin(int argc, char **argv)
{
	size_t	i;

	(void)argv;
	if (!g_shell_environment)
		return (EXIT_FAILURE);
	i = 0;
	if (argc == 1)
	{
		while (g_shell_environment[i])
		{
			printf("%s\n", g_shell_environment[i]);
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
