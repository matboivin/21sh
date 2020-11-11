/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 15:31:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int			main(int argc, char **argv, char **envp)
{
	(void)argv;
	if (argc != DEFAULT_ARGC)
		print_usage();
	start_shell(envp);
	return (shell_loop());
}
