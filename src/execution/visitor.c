/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 15:28:52 by ouram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	in_order(t_ast_node	*node)
{
	if (!node)
		return ;
}

