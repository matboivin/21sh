/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:52:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 13:00:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_execution.h"

/*
** Redirecting Input
**   <  :  O_RDONLY
*/

static void	redir_input(int *fd, char *node_data)
{
	if (is_open_file(*fd))
		close(*fd);
	*fd = open(node_data, O_RDONLY);
	if (*fd == FAIL_RET)
	{
		print_errno(node_data);
		g_status = EXIT_FAILURE;
	}
}

/*
** Redirecting Output
**   >  :  O_WRONLY | O_CREAT | O_TRUNC
*/

static void	redir_output(int *fd, char *node_data)
{
	if (is_open_file(*fd))
		close(*fd);
	*fd = open(node_data, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	if (*fd == FAIL_RET)
	{
		print_errno(node_data);
		g_status = EXIT_FAILURE;
	}
}

/*
** Appending Redirected Output
**   >> :  O_WRONLY | O_CREAT | O_APPEND
*/

static void	redir_append_output(int *fd, char *node_data)
{
	if (is_open_file(*fd))
		close(*fd);
	*fd = open(node_data, O_WRONLY | O_CREAT | O_APPEND, FILE_PERMISSIONS);
	if (*fd == FAIL_RET)
	{
		print_errno(node_data);
		g_status = EXIT_FAILURE;
	}
}

/*
** This function open files for redirections
*/

static void	open_files(t_simplecmd *simple_cmd, t_ast_node *node)
{
	if (!node || node->type != NODE_IO_FILE)
		return ;
	if (!ft_strcmp(node->data, REDIR_INPUT))
		redir_input(&(simple_cmd->input_fd), node->left->data);
	else if (!ft_strcmp(node->data, REDIR_OUTPUT))
		redir_output(&(simple_cmd->output_fd), node->left->data);
	else if (!ft_strcmp(node->data, REDIR_APPEND_OUTPUT))
		redir_append_output(&(simple_cmd->output_fd), node->left->data);
	open_files(simple_cmd, node->right);
}

void		get_files(t_simplecmd *simple_cmd, t_ast_node *node)
{
	open_files(simple_cmd, node->left);
	if (node->right && node->right->type == NODE_CMD_SUFFIX)
		open_files(simple_cmd, node->right->right);
}
