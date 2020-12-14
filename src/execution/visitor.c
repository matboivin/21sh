/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 16:15:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_execution.h"

void	visit_simple_cmd(t_ast_node *node, t_cmd *cmds)
{
	(void)node;
	(void)cmds;
}

/*
** This function visits an AST node
*/

void	visit(t_ast_node *node, t_cmd *cmds)
{
	(void)cmds;
	if (!node->data)
		return ;
	ft_printf("%s ", node->data);
}

/*
** This function traverses the AST following the in-order pattern
*/

void	traverse_tree(t_ast_node *node, t_cmd *cmds)
{
	if (!node)
		return ;
	traverse_tree(node->left, cmds);
	visit(node, cmds);
	traverse_tree(node->right, cmds);
}
