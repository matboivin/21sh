/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:52:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 23:06:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_execution.h"

/*
** This function open files for redirections
**
** Redirecting Input
**   <  :  O_RDONLY
** Redirecting Output
**   >  :  O_WRONLY | O_CREAT | O_TRUNC
** Appending Redirected Output
**   >> :  O_WRONLY | O_CREAT | O_APPEND
*/

// TODO: Keep the last io_file in the list

static void	open_files(t_simplecmd *result, t_ast_node *node)
{
	if (!node || node->type != NODE_IO_FILE)
		return ;
	// TODO: open file with expected flags
	open_files(result, node->right);
}

void		get_files(t_simplecmd *result, t_ast_node *node)
{
	open_files(result, node->left);
	if (node->right && node->right->type == NODE_CMD_SUFFIX)
		open_files(result, node->right->right);
}
