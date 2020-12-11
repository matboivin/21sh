/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 16:37:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_execution.h"

/*
** In-Order (LNR) search pseudo-code
**
** inorder(node)
**    if (node == null)
**        return
**    inorder(node.left)
**    visit(node)
**    inorder(node.right)
*/

void	visit(t_ast_node *node)
{
	if (!node->data)
		return ;
	ft_printf("%s ", node->data);
}

void	traverse_tree(t_ast_node *node)
{
	if (!node)
		return ;
	traverse_tree(node->left);
	visit(node);
	traverse_tree(node->right);
}

