/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 21:24:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				main(int argc, char **argv, char **envp)
{
	t_shctrl	ft_sh;

	(void)argv;
	if (argc != DEFAULT_ARGC)
		print_usage();
	start_shell(envp);
	create_shell(&ft_sh, DEFAULT_CAPACITY);
	return (shell_loop(ft_sh));
}
