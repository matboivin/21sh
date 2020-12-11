/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 15:41:55 by ouram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_visitor.h"

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
	ft_printf("node: %s\n", node->data);
}

void	traverse_tree(t_ast_node *node)
{
	if (!node)
		return ;
	traverse_tree(node->left);
	visit(node);
	traverse_tree(node->right);
}



