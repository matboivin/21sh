/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:46:26 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:23:31 by mboivin          ###   ########.fr       */
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

static t_simplecmd	*get_simple_cmd(t_ast_node *node)
{
	t_simplecmd		*result;

	result = malloc_simple_cmd();
	if (!result)
		return (NULL);
	get_cmd_arg_count(result, node);
	get_cmd_args(result, node);
	// TODO: fd
	return (result);
}

int					add_simple_cmd(t_cmd *cmd, t_ast_node *node)
{
	cmd->simple_cmds[cmd->cmd_count] = get_simple_cmd(node);
	if (!cmd->simple_cmds[cmd->cmd_count])
		return (0);
	cmd->cmd_count += 1;
	return (1);
}
