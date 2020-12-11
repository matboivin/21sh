/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 15:35:37 by ouram            ###   ########.fr       */
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

void	in_order(t_ast_node	*node)
{
	if (!node)
		return ;
	if_order(node->left);
	visit(node);
	if_order(node->right);
}

