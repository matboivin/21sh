/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stream.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 23:43:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh_execution.h"

void	restore_default_streams(t_streams backup)
{
	redirect_stream(backup.in, STDIN_FILENO);
	redirect_stream(backup.out, STDOUT_FILENO);
}

void	dup_streams(t_streams *backup)
{
	backup->in = dup(STDIN_FILENO);
	backup->out = dup(STDOUT_FILENO);
}

void	redirect_stream(int from, int to)
{
	if ((!is_open_file(from)) || (!is_open_file(to)) || (from == to))
		return ;
	if (dup2(from, to) != FAIL_RET)
		close(from);
}

void	handle_redirection(t_simplecmd *simple_cmd, t_streams *backup)
{
	dup_streams(backup);
	redirect_stream(simple_cmd->input_fd, STDIN_FILENO);
	redirect_stream(simple_cmd->output_fd, STDOUT_FILENO);
}
