/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 16:25:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXECUTION_H
# define SH_EXECUTION_H

# include <stdbool.h>
# include "sh_define.h"
# include "sh_ast.h"
# include "sh_command.h"
# include "sh_ctrl.h"

/*
** Traverses the AST following the pre-order pattern
*/

void	traverse_tree(t_shctrl *ft_sh, t_ast_node *node);

/*
** Visits an AST node
*/

void	visit(t_shctrl *ft_sh, t_ast_node *node);

/*
** Builds a command table for each command node
*/

void	build_cmd_table(t_shctrl *ft_sh);

/*
** Checks whether the current simple command is the last one
*/

bool	is_last_command(size_t cmd_i, size_t cmd_count);

/*
** Executes all simple commands
*/

void	execute(t_cmd *cmd);

/*
** Executes a simple command
*/

void	exec_simple_cmd(t_simplecmd *simple_cmd);

/*
** Spawns a new process
*/

void	spawn_process(pid_t *pid);

void	create_pipe(int *input_fd, int *output_fd);
void	redirect_fd(int from, int to);

#endif
