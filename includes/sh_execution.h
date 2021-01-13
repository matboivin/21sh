/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:13:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXECUTION_H
# define SH_EXECUTION_H

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include "sh_define.h"
# include "sh_command.h"
# include "sh_ctrl.h"

typedef struct	s_streams
{
	int			in;
	int			out;
}				t_streams;

/*
** Redirections
*/

void	handle_redirection(t_simplecmd *simple_cmd, t_streams *backup);
void	redirect_stream(int from, int to);
void	restore_default_streams(t_streams backup);
void	dup_streams(t_streams *backup);

/*
** Check whether the current simple command is a shell builtin
*/

bool	is_builtin(t_simplecmd *simple_cmd);

/*
** Executes all simple commands
*/

void	execute(t_shctrl *ft_sh, t_cmd *cmd);

/*
** This function executes a pipe sequence
*/

void	exec_pipe_seq(t_shctrl *ft_sh, t_cmd *cmd);

/*
** Executes a simple command
*/

void	exec_simple_cmd(t_simplecmd *simple_cmd);

/*
** Invokes a shell builtin
*/

void	invoke_builtin(t_simplecmd *builtin);

/*
** Spawns a new process to execute a simple command
*/

void	spawn_process(t_shctrl *ft_sh, pid_t *pid);

#endif
