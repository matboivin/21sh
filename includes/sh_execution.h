/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 18:20:50 by mboivin          ###   ########.fr       */
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
** Traverses the AST following the in-order pattern
*/

void	traverse_tree(t_ast_node *node);

/*
** Visits an AST node
*/

void	visit(t_ast_node *node);

/*
** Builds a command table for each command node
*/

void	build_cmd_table(t_ast_node *node);

/*
** Checks whether the current simple command is the last one
*/

bool	is_last_command(size_t cmd_i, size_t cmd_count);

/*
** Executes a simple command
*/

void	exec_simple_cmd(t_simplecmd *simple_cmd);

#endif
