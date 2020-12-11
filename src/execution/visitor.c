/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 17:41:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_execution.h"

void	visit_simple_cmd(t_ast_node *node)
{
	(void)node;
	//if (node->left->type == NODE_WORD)
}

/*
** This function visits an AST node
*/

void	visit(t_ast_node *node)
{
	if (!node->data)
		return ;
	if (node->type == NODE_SIMPLE_CMD)
		visit_simple_cmd(node);
}

/*
** This function traverses the AST following the in-order pattern
*/

void	traverse_tree(t_ast_node *node)
{
	if (!node)
		return ;
	traverse_tree(node->left);
	visit(node);
	traverse_tree(node->right);
}
