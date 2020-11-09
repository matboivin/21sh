/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 22:02:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "libft_printf.h"
#include "ft_sh.h"

int			main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != DEFAULT_ARGC)
		print_usage();
	init_env(envp);
	ft_printenv(); // tmp tests
	ft_printf("\nValue of SHELL: %s\n", ft_getenv("SHELL"));
	g_env = ft_putenv("FOO=foo/foo/foo");
	ft_printf("\nValue of FOO: %s\n\n", ft_getenv("FOO"));
	ft_setenv("FOO", "bar/bar/bar", true);
	ft_printf("Value of FOO: %s\n\n", ft_getenv("FOO"));
	ft_printenv();
	ft_clearenv();
	return (0);
}
