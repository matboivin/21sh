/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 16:37:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXECUTION_H
# define SH_EXECUTION_H

# include <stdbool.h>
# include "sh_ast.h"

/*
** Visits an AST node
*/

void	visit(t_ast_node *node);

/*
** Traverses the AST following the in-order pattern
*/

void	traverse_tree(t_ast_node *node);

/*
** Checks whether the current simple command is the last one
*/

bool	is_last_command(size_t cmd_i, size_t cmd_count);

#endif
