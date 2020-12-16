/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:13:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 20:30:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_execution.h"

/*
** This function retrieves a simple command args
*/

static void	fill_args(t_simplecmd *simple_cmd, size_t i, t_ast_node *node)
{
	if (!node || node->type != NODE_WORD)
		return ;
	if (i < simple_cmd->argc)
		simple_cmd->cmd_args[i] = ft_strdup(node->data);
	fill_args(simple_cmd, i + 1, node->right);
}

void		get_cmd_args(t_simplecmd *simple_cmd, t_ast_node *node)
{
	size_t	i;

	if (!simple_cmd->argc)
		return ;
	i = 0;
	simple_cmd->cmd_args = malloc((simple_cmd->argc + 1) * sizeof(char *));
	if (!simple_cmd->cmd_args)
		return ;
	simple_cmd->cmd_args[simple_cmd->argc] = NULL;
	fill_args(simple_cmd, i, node->left);
	if (node->right && (node->right->type == NODE_CMD_SUFFIX))
		fill_args(simple_cmd, i + 1, node->right->left);
}
