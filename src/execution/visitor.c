/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:11:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 17:43:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_printf.h"
#include "sh_execution.h"

/*
** This function visits an AST node
*/

void	visit(t_ast_node *node)
{
	if (node->type == NODE_CMD)
	{
		build_cmd_table(node);
		return ;
	}
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
