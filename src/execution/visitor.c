/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 16:49:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_printf.h"
#include "sh_execution.h"

/*
** This function visits an AST node
*/

void	visit(t_shctrl *ft_sh, t_ast_node *node)
{
	if (node->type == NODE_CMD)
	{
		ft_printf("\n----------- TODO: Build command table\n");
		build_cmd_table(ft_sh);
		free_cmd(&(ft_sh->cmd)); // tmp test
	}
	if (node->type == NODE_PIPE_SEQ)
	{
		ft_printf("\n----------- TODO: Get all simple commands\n");
		if (!node->right)
		{
			ft_printf("\n----------- TODO: Execute command\n");
			return ;
		}
	}
	if (node->data)
		ft_printf("%s ", node->data);
}

/*
** This function traverses the AST following the pre-order pattern
*/

void	traverse_tree(t_shctrl *ft_sh, t_ast_node *node)
{
	if (!node)
		return ;
	visit(ft_sh, node);
	traverse_tree(ft_sh, node->left);
	traverse_tree(ft_sh, node->right);
}
