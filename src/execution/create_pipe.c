/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/19 21:24:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

void	create_pipe(t_shctrl *ft_sh, t_streams *swap)
{
	int	pfd[2];

	if (pipe(pfd) == FAIL_RET)
	{
		print_errno("pipe");
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
	swap->input = pfd[READ_END];
	swap->output = pfd[WRITE_END];
}
