/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_arg_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:13:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:58:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_execution.h"

/*
** This function counts a simple command arg
*/

static void	count_args(t_simplecmd *result, t_ast_node *node)
{
	if (!node || node->type != NODE_WORD)
		return ;
	result->argc++;
	count_args(result, node->right);
}

void		get_cmd_arg_count(t_simplecmd *result, t_ast_node *node)
{
	count_args(result, node->left);
	if (node->right && node->right->type == NODE_CMD_SUFFIX)
		count_args(result, node->right->left);
}
