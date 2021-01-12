/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_arg_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:13:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 22:18:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_execution.h"

/*
** This function counts a simple command arg
*/

static void	count_args(t_simplecmd *simple_cmd, t_ast_node *node)
{
	if (!node || node->type != NODE_WORD)
		return ;
	simple_cmd->argc++;
	count_args(simple_cmd, node->right);
}

void		get_cmd_arg_count(t_simplecmd *simple_cmd, t_ast_node *node)
{
	count_args(simple_cmd, node->left);
	if (node->right && node->right->type == NODE_CMD_SUFFIX)
		count_args(simple_cmd, node->right->left);
	else if (node->right && node->right->type == NODE_WORD)
		count_args(simple_cmd, node->right);
}
