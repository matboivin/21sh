/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:53:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

void	create_pipe(t_shctrl *ft_sh, int *input_fd, int *output_fd)
{
	int	pfd[2];

	if (pipe(pfd) == FAIL_RET)
	{
		print_error("pipe");
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
	*output_fd = pfd[WRITE_END];
	*input_fd = pfd[READ_END];
}
