/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:52:10 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:11:53 by mboivin          ###   ########.fr       */
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
#include "sh_expansion.h"

/*
** Redirecting Input
**   <  :  O_RDONLY
*/

static int	redir_input(int *fd, char *node_data)
{
	if (is_open_file(*fd))
		close(*fd);
	*fd = open(node_data, O_RDONLY);
	if (*fd == FAIL_RET)
	{
		print_errno(node_data);
		g_status = EXIT_FAILURE;
		return (FAIL_RET);
	}
	return (0);
}

/*
** Redirecting Output
**   >  :  O_WRONLY | O_CREAT | O_TRUNC
*/

static int	redir_output(int *fd, char *node_data)
{
	if (is_open_file(*fd))
		close(*fd);
	*fd = open(node_data, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	if (*fd == FAIL_RET)
	{
		print_errno(node_data);
		g_status = EXIT_FAILURE;
		return (FAIL_RET);
	}
	return (0);
}

/*
** Appending Redirected Output
**   >> :  O_WRONLY | O_CREAT | O_APPEND
*/

static int	redir_append_output(int *fd, char *node_data)
{
	if (is_open_file(*fd))
		close(*fd);
	*fd = open(node_data, O_WRONLY | O_CREAT | O_APPEND, FILE_PERMISSIONS);
	if (*fd == FAIL_RET)
	{
		print_errno(node_data);
		g_status = EXIT_FAILURE;
		return (FAIL_RET);
	}
	return (0);
}

/*
** This function open files for redirections
*/

static int	open_files(t_simplecmd *simple_cmd, t_ast_node *node)
{
	int		ret;

	ret = 0;
	if (!node || node->type != NODE_IO_FILE)
		return (0);
	if (!ft_strcmp(node->data, REDIR_INPUT))
		ret = redir_input(&(simple_cmd->input_fd), node->left->data);
	else if (!ft_strcmp(node->data, REDIR_OUTPUT))
		ret = redir_output(&(simple_cmd->output_fd), node->left->data);
	else if (!ft_strcmp(node->data, REDIR_APPEND_OUTPUT))
		ret = redir_append_output(&(simple_cmd->output_fd), node->left->data);
	if (ret == FAIL_RET)
		return (FAIL_RET);
	return (open_files(simple_cmd, node->right));
}

int			get_files(t_simplecmd *simple_cmd, t_ast_node *node)
{
	int		ret;

	ret = open_files(simple_cmd, node->left);
	if (!ret && node->right && (node->right->type == NODE_CMD_SUFFIX))
		ret = open_files(simple_cmd, node->right->right);
	return (ret);
}
