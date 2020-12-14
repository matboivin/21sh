/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:05:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 18:59:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_execution.h"

/*
** This function builds a command table for each command node
*/

/*
** Tmp comment - TODO
** - for each pipe seq
**   - for each simple command
**     - count args
**     - store args
**     - open fd
**     - spawn process
**
**                  NODE_CMD
**                  /      \
**      NODE_PIPE_SEQ      NODE_CMD
**              /
**  NODE_SIMPLE_CMD
**
**      NODE_SIMPLE_CMD                 NODE_SIMPLE_CMD
**             /                               /
**         "cmd_name"                      NODE_IO_FILE
**
**      NODE_SIMPLE_CMD                  NODE_SIMPLE_CMD
**        /         \                     /         \
** NODE_IO_FILE   "cmd_name"        "cmd_name"      NODE_CMD_SUFFIX
**
**                        NODE_SIMPLE_CMD
**                         /           \
**                 NODE_IO_FILE     "cmd_name"
**                                       \
**                                 NODE_CMD_SUFFIX
*/

void			build_cmd_table(t_ast_node *node)
{
	t_cmd		*cmd;
	t_ast_node	*cursor;

	cmd = malloc_cmd(DEFAULT_CAPACITY);
	cursor = node->left->left; // tmp test
	get_simple_cmd(cmd, cursor);
#ifdef DEBUG
	print_cmd(cmd);
#endif /* DEBUG */
	free_cmd(&cmd);
}
