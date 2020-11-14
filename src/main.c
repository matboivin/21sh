/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:06:31 by mboivin          ###   ########.fr       */
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
	create_shell(&ft_sh);
	return (shell_loop(&ft_sh));
}
