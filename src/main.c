/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:30:41 by mboivin           #+#    #+#             */
/*   Updated: 2021/02/19 16:13:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

/*
** ft_sh
** A minimalist interactive shell mimicking bash
*/

int				main(int argc, char **argv, char **envp)
{
	t_shctrl	ft_sh;

	if (argc != NO_ARGS)
		print_usage(argv[0]);
	create_shell(&ft_sh);
	start_shell(envp);
	return (wait_for_input(&ft_sh));
}
