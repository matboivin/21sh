/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:46:26 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/19 13:15:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft_str.h"
#include "sh_expansion.h"

/*
** This function adds a simple command to the command table
*/

static t_simplecmd	*get_simple_cmd(t_ast_node *node)
{
	t_simplecmd		*result;
	int				ret;

	ret = 0;
	result = malloc_simple_cmd();
	if (!result)
		return (NULL);
	get_cmd_arg_count(result, node);
	get_cmd_args(result, node);
	ret = get_files(result, node);
	if (ret != FAIL_RET)
	{
		ret = search_command(result);
		if (ret != FAIL_RET)
			return (result);
	}
	free_simple_cmd(result);
	return (NULL);
}

void				add_simple_cmd(t_cmd *cmd, t_ast_node *node)
{
	cmd->simple_cmds[cmd->cmd_count] = get_simple_cmd(node);
	if (cmd->simple_cmds[cmd->cmd_count])
		cmd->cmd_count += 1;
}
