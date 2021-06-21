/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/21 19:40:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "shell.h"
#include "builtins.h"
#include "libft_str.h"

/*
 * A minimalist interactive shell mimicking bash
 */

static int	reader_loop(void)
{
	// tmp
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*shell;

	shell = NULL;
	if (argc > 1 && !ft_strcmp(argv[1], "--help"))
	{
		put_shell_usage(argv[0]);
		return (0);
	}
	shell = init_shell();
	// init
	set_shell(shell, argc, argv, envp);
	if (shell->interactive_shell)
		reader_loop();
	exit_shell(&shell);
	return (0);
}
