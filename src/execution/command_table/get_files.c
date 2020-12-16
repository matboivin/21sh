/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:52:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 17:59:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft_printf.h"
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
	if (!ft_strcmp(node->data, REDIR_INPUT))
	{
		ft_printf("%s %s\n", node->data, node->left->data);
		// if (result->in_fd != -1)
		// 	close(result->in_fd);
		// result->in_fd = open(node->left->data, O_RDONLY);
	}
	else if (!ft_strcmp(node->data, REDIR_OUTPUT))
	{
		if (result->out_fd != -1)
			close(result->out_fd);
		result->out_fd = open(
			node->left->data, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	}
	else if (!ft_strcmp(node->data, REDIR_APPEND_OUTPUT))
	{
		if (result->out_fd != -1)
			close(result->out_fd);
		result->out_fd = open(
			node->left->data, O_WRONLY | O_CREAT | O_APPEND, FILE_PERMISSIONS);
	}
	open_files(result, node->right);
}

void		get_files(t_simplecmd *result, t_ast_node *node)
{
	open_files(result, node->left);
	if (node->right && node->right->type == NODE_CMD_SUFFIX)
		open_files(result, node->right->right);
}
