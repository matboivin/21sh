/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/19 20:57:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

void	create_pipe(t_shctrl *ft_sh, t_streams *swap)
{
	int	pfd[2];

	if (pipe(pfd) == FAIL_RET)
	{
		print_error("pipe", strerror(errno));
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
	swap->input = pfd[READ_END];
	swap->output = pfd[WRITE_END];
}
