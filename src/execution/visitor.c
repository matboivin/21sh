/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 20:06:25 by ouram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function visits an AST node
*/

void	visit(t_shctrl *ft_sh, t_ast_node *node)
{
	if (node->type == NODE_CMD)
		build_cmd_table(ft_sh);
	else if (node->type == NODE_PIPE_SEQ)
	{
		if (!add_simple_cmd(ft_sh->cmd, node->left))
			exit_shell(ft_sh);
		if (!node->right)
		{
#ifdef DEBUG
			print_cmd(ft_sh->cmd);
#endif /* DEBUG */
			execute(ft_sh, ft_sh->cmd);
			free_cmd(&(ft_sh->cmd));
		}
	}
}

/*
** This function traverses the AST to build the command table
*/

void	traverse_tree(t_shctrl *ft_sh, t_ast_node *node)
{
	if (!node)
		return ;
	visit(ft_sh, node);
	if (node->type == NODE_CMD)
		traverse_tree(ft_sh, node->left);
	traverse_tree(ft_sh, node->right);
}
