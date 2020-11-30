/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:58:43 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 19:01:04 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_ast.h"

/*
** This function adds a leaf node to the left of the tree
*/

void			append_node_left(t_ast_node **root, t_ast_node *new_node)
{
	t_ast_node	*cursor;

	if (!root || !new_node)
		return ;
	if (*root)
	{
		cursor = *root;
		while (cursor->left)
			cursor = cursor->left;
		cursor->left = new_node;
	}
	else
		*root = new_node;
}

/*
** This function adds a leaf node to the right of the tree
*/

void			append_node_right(t_ast_node **root, t_ast_node *new_node)
{
	t_ast_node	*cursor;

	if (!root || !new_node)
		return ;
	if (*root)
	{
		cursor = *root;
		while (cursor->right)
			cursor = cursor->right;
		cursor->right = new_node;
	}
	else
		*root = new_node;
}
