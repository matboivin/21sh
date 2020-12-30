/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:13:06 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 19:08:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_subsystems.h"
#include "sh_execution.h"

/*
** This function retrieves a simple command args
*/

static void		fill_args(t_simplecmd *simple_cmd, size_t i, t_ast_node *node)
{
	if (!node || node->type != NODE_WORD)
		return ;
	if (i < simple_cmd->argc)
	{
		simple_cmd->cmd_args[i] = ft_strdup(node->data);
		substitute_word(&(simple_cmd->cmd_args[i]));
		remove_quotes(&(simple_cmd->cmd_args[i]));
	}
	fill_args(simple_cmd, i + 1, node->right);
}

void			get_cmd_args(t_simplecmd *simple_cmd, t_ast_node *node)
{
	t_ast_node	*cursor;
	size_t		i;

	if (!simple_cmd->argc)
		return ;
	i = 0;
	cursor = node;
	simple_cmd->cmd_args = malloc((simple_cmd->argc + 1) * sizeof(char *));
	if (!simple_cmd->cmd_args)
		return ;
	simple_cmd->cmd_args[simple_cmd->argc] = NULL;
	if (cursor->left && (cursor->left->type == NODE_IO_FILE))
	{
		fill_args(simple_cmd, i, cursor->right);
		cursor = cursor->right;
	}
	else
		fill_args(simple_cmd, i, cursor->left);
	if (cursor->right && (cursor->right->type == NODE_CMD_SUFFIX))
		fill_args(simple_cmd, i + 1, cursor->right->left);
	simple_cmd->cmd_path = ft_strdup(simple_cmd->cmd_args[CMD_NAME]);
}
