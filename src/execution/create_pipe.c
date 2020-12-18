/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/18 22:42:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "sh_utils.h"
#include "sh_execution.h"

void	create_pipe(t_shctrl *ft_sh, int *input_fd, int *output_fd)
{
	int	pfd[2];

	if (pipe(pfd) == FAIL_RET)
	{
		print_error("pipe", strerror(errno));
		g_status = EXIT_FAILURE;
		exit_shell(ft_sh);
	}
	*input_fd = pfd[READ_END];
	*output_fd = pfd[WRITE_END];
}
