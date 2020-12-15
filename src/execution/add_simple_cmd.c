/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:46:26 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:03:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_printf.h"
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function adds a simple command to the command table
*/

// tmp count

static void	traverse_args(t_simplecmd *result, t_ast_node *node)
{
	if (!node || node->type != NODE_WORD)
		return ;
	result->argc++;
	traverse_args(result, node->right);
}

static void	count_args(t_simplecmd *result, t_ast_node *node)
{
	traverse_args(result, node->left);
	if (node->right && node->right->type == NODE_CMD_SUFFIX)
		traverse_args(result, node->right->left);
}

static void	traverse_args2(t_simplecmd *result, size_t i, t_ast_node *node)
{
	if (!node || node->type != NODE_WORD)
		return ;
	if (i < result->argc)
		result->cmd_args[i] = ft_strdup(node->data);
	traverse_args2(result, i + 1, node->right);
}

static void	fill_args(t_simplecmd *result, t_ast_node *node)
{
	size_t	i;

	i = 0;
	traverse_args2(result, i, node->left);
	if (node->right && (node->right->type == NODE_CMD_SUFFIX))
		traverse_args2(result, i + 1, node->right->left);
}

static void	get_args(t_simplecmd *result, t_ast_node *node)
{
	count_args(result, node);
	if (!result->argc)
		return ;
	result->cmd_args = malloc((result->argc + 1) * sizeof(char *));
	if (!result->cmd_args)
		return ;
	result->cmd_args[result->argc] = NULL;
	fill_args(result, node);
}

t_simplecmd	*get_simple_cmd(t_ast_node *node)
{
	t_simplecmd	*result;

	result = malloc_simple_cmd();
	if (!result)
		return (NULL);
	get_args(result, node);
	return (result);
}

int			add_simple_cmd(t_cmd *cmd, t_ast_node *node)
{
	cmd->simple_cmds[cmd->cmd_count] = get_simple_cmd(node);
	if (!cmd->simple_cmds[cmd->cmd_count])
		return (0);
	cmd->cmd_count += 1;
	return (1);
}
