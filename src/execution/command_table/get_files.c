/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:52:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 18:44:40 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft_printf.h"
#include "sh_execution.h"

/*
** Redirecting Input
**   <  :  O_RDONLY
*/

static void	redir_input(int *fd, char *node_data)
{
	if (*fd != -1)
		close(*fd);
	*fd = open(node_data, O_RDONLY);
}

/*
** Redirecting Output
**   >  :  O_WRONLY | O_CREAT | O_TRUNC
*/

static void	redir_output(int *fd, char *node_data)
{
	if (*fd != -1)
		close(*fd);
	*fd = open(node_data, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
}

/*
** Appending Redirected Output
**   >> :  O_WRONLY | O_CREAT | O_APPEND
*/

static void	redir_append_output(int *fd, char *node_data)
{
	if (*fd != -1)
		close(*fd);
	*fd = open(node_data, O_WRONLY | O_CREAT | O_APPEND, FILE_PERMISSIONS);
}

/*
** This function open files for redirections
*/

static void	open_files(t_simplecmd *result, t_ast_node *node)
{
	if (!node || node->type != NODE_IO_FILE)
		return ;
	if (!ft_strcmp(node->data, REDIR_INPUT))
		redir_input(&(result->in_fd), node->left->data);
	else if (!ft_strcmp(node->data, REDIR_OUTPUT))
		redir_output(&(result->out_fd), node->left->data);
	else if (!ft_strcmp(node->data, REDIR_APPEND_OUTPUT))
		redir_append_output(&(result->out_fd), node->left->data);
	open_files(result, node->right);
}

void		get_files(t_simplecmd *result, t_ast_node *node)
{
	open_files(result, node->left);
	if (node->right && node->right->type == NODE_CMD_SUFFIX)
		open_files(result, node->right->right);
}
