/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stream.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 22:27:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh_execution.h"

void	restore_default_streams(t_streams backup)
{
	redirect_stream(backup.in, STDIN_FILENO);
	redirect_stream(backup.out, STDOUT_FILENO);
}

void	backup_streams(t_streams *backup)
{
	backup->in = dup(STDIN_FILENO);
	backup->out = dup(STDOUT_FILENO);
}

void	redirect_stream(int from, int to)
{
	if ((!is_open_file(from)) || (!is_open_file(to)))
		return ;
	dup2(from, to);
	close(from);
}
