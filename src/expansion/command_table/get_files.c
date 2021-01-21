/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:52:10 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/21 15:07:29 by mboivin          ###   ########.fr       */
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

static int		open_fd(int *fd, int flags, char *filename)
{
	if (is_open_file(*fd))
		close(*fd);
	*fd = open(filename, flags, FILE_PERMISSIONS);
	if (*fd == FAIL_RET)
	{
		print_errno(filename);
		g_status = EXIT_FAILURE;
		return (FAIL_RET);
	}
	return (0);
}

static int		handle_fd(t_simplecmd *simple_cmd, int type, int flags, char *node_data)
{
	int			ret;
	char		*filename;

	ret = 0;
	filename = ft_strdup(node_data);
	expand_word(&filename);
	if (type == REDIR_OUT)
		ret = open_fd(&(simple_cmd->output_fd), flags, filename);
	else
		ret = open_fd(&(simple_cmd->input_fd), flags, filename);
	ft_strdel(&filename);
	return (ret);
}

/*
** Redirecting Input
**   <  :  O_RDONLY
**
** Redirecting Output
**   >  :  O_WRONLY | O_CREAT | O_TRUNC
**
** Appending Redirected Output
**   >> :  O_WRONLY | O_CREAT | O_APPEND
*/

static void		set_up_opt(char *op, int *flags, int *type)
{
	if (!ft_strcmp(op, REDIR_INPUT))
	{
		*type = REDIR_IN;
		*flags = O_RDONLY;
	}
	else if (!ft_strcmp(op, REDIR_OUTPUT))
	{
		*type = REDIR_OUT;
		*flags = O_WRONLY | O_CREAT | O_TRUNC;
	}
	else if (!ft_strcmp(op, REDIR_APPEND_OUTPUT))
	{
		*type = REDIR_OUT;
		*flags = O_WRONLY | O_CREAT | O_APPEND;
	}
}

/*
** This function open files for redirections
*/

static int		open_files(t_simplecmd *simple_cmd, t_ast_node *node)
{
	int			flags;
	int			type;
	int			ret;

	ret = 0;
	if (!node || node->type != NODE_IO_FILE)
		return (0);
	set_up_opt(node->data, &flags, &type);
	ret = handle_fd(simple_cmd, type, flags, node->left->data);
	if (ret == FAIL_RET)
		return (FAIL_RET);
	return (open_files(simple_cmd, node->right));
}

int				get_files(t_simplecmd *simple_cmd, t_ast_node *node)
{
	t_ast_node	*cursor;
	int			ret;

	cursor = node;
	ret = open_files(simple_cmd, cursor->left);
	if (cursor->right)
	{
		cursor = cursor->right;
		if (!ret && (cursor->type == NODE_CMD_SUFFIX))
			ret = open_files(simple_cmd, cursor->right);
		else if ((cursor->type == NODE_WORD) && cursor->right)
		{
			cursor = cursor->right;
			if (cursor->type == NODE_CMD_SUFFIX)
				ret = open_files(simple_cmd, cursor->right);
		}
	}
	return (ret);
}
