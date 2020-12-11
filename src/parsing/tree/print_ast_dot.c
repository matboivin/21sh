/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 13:45:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft_printf.h"
#include "sh_ast.h"

/*
** This function creates a dot graph from a given Abstract Syntax Tree (AST)
*/

static char	*get_type_name(t_node_type n)
{
	char	*node_names[7];

	node_names[NODE_PROGRAM] = "Program";
	node_names[NODE_CMD] = "Command";
	node_names[NODE_CMD_SUFFIX] = "Cmd suffix";
	node_names[NODE_WORD] = "Word";
	node_names[NODE_IO_FILE] = "IO File";
	node_names[NODE_PIPE_SEQ] = "Pipe sequence";
	node_names[NODE_SIMPLE_CMD] = "Simple Command";
	return (node_names[n]);
}

static void	print_node(int fd, t_ast_node *node, int i)
{
	if (node->data)
		ft_dprintf(fd, "\n    \"%s\\n%d\"", node->data, i);
	else
		ft_dprintf(fd, "\n    \"%s\\n%d\"", get_type_name(node->type), i);
}

static void	print_node_next(int fd, t_ast_node *node, int i)
{
	if (node->data)
		ft_dprintf(fd, " -> \"%s\\n%d\";", node->data, i + 1);
	else
		ft_dprintf(fd, " -> \"%s\\n%d\";", get_type_name(node->type), i + 1);
}

static void	write_branch(int fd, t_ast_node *node, int i)
{
	if (node->left)
	{
		print_node(fd, node, i);
		print_node_next(fd, node->left, i);
		write_branch(fd, node->left, i + 1);
	}
	if (node->right)
	{
		print_node(fd, node, i);
		print_node_next(fd, node->right, i);
		write_branch(fd, node->right, i + 1);
	}
}

static void	write_ast(int fd, t_ast_node *root)
{
	ft_dprintf(fd, "digraph minishell_parsing {");
	if (!root->left && !root->right)
		ft_dprintf(fd, "\n    \"%s\";", root->data);
	else
		write_branch(fd, root, 0);
	ft_dprintf(fd, "\n}");
}

void		save_ast_dot(t_ast_node *root)
{
	int		fd;

	if (!root)
		return ;
	fd = open(AST_DOT_FILE, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	if (!fd)
		exit(EXIT_FAILURE);
	write_ast(fd, root);
	close(fd);
}
