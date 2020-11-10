/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 13:58:16 by mboivin          ###   ########.fr       */
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
	/* Env functions tests */
	ft_printf("----------- ORIGINAL ENV -----------\n\n");
	ft_printenv();
	ft_printf("\n\n----------- ADDED FOO VAR ----------\n\n");
	ft_putenv("FOO=foo/foo/foo");
	ft_printenv();
	ft_printf("\nValue of FOO: %s\n\n", ft_getenv("FOO"));
	ft_printf("--------- UPDATE FOO VALUE ----------\n\n");
	ft_printenv();
	ft_setenv("FOO", "bar/bar/bar", true);
	ft_printf("\nValue of FOO: %s\n\n", ft_getenv("FOO"));
	ft_printf("------------- RM FOO VAR ------------\n\n");
	ft_unsetenv("FOO");
	ft_printenv();
	ft_printf("\nReturn of setenv with '=': %d\n", ft_setenv("FOO=", "bar/bar/bar", true));
	ft_printf("Return of putenv without '=': %d\n", ft_putenv("FOO"));
	ft_printf("Return of unsetenv with '=': %d\n", ft_unsetenv("FOO="));
	ft_clearenv();
	return (0);
}
