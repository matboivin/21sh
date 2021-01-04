/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/04 13:34:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				main(int argc, char **argv, char **envp)
{
	t_shctrl	ft_sh;

	if (argc != NO_ARGS)
		print_usage(argv[0]);
	start_shell(envp);
	create_shell(&ft_sh);
	return (shell_loop(&ft_sh));
}
