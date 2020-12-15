/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:13:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:22:08 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function retrieves a simple command args
*/

static void	fill_args(t_simplecmd *result, size_t i, t_ast_node *node)
{
	if (!node || node->type != NODE_WORD)
		return ;
	if (i < result->argc)
		result->cmd_args[i] = ft_strdup(node->data);
	fill_args(result, i + 1, node->right);
}

void		get_cmd_args(t_simplecmd *result, t_ast_node *node)
{
	size_t	i;

	if (!result->argc)
		return ;
	i = 0;
	result->cmd_args = malloc((result->argc + 1) * sizeof(char *));
	if (!result->cmd_args)
		return ;
	result->cmd_args[result->argc] = NULL;
	fill_args(result, i, node->left);
	if (node->right && (node->right->type == NODE_CMD_SUFFIX))
		fill_args(result, i + 1, node->right->left);
}
