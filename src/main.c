/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 00:38:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(int argc, char **argv, char **envp)
{
	t_shctrl	ft_sh;

	(void)argv;
	if (argc != NO_ARGS)
		print_usage();
	start_shell(envp);
	create_shell(&ft_sh);
	return (shell_loop(&ft_sh));
}
