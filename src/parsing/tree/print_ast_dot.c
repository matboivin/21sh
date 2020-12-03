/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/03 17:43:32 by mboivin          ###   ########.fr       */
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

static void	write_leaf(int fd, t_ast_node *node)
{
	ft_dprintf(
		fd, "\n    \"%s:\\n%s\";",
		get_type_name(node->type),
		node->data);
}

static void	write_branch(int fd, t_ast_node *node, int i)
{
	if (node->left)
	{
		ft_dprintf(
			fd, "\n    \"%s_%d:\\n%s\" -> \"%s_%d:\\n%s\";",
			get_type_name(node->type), i,
			node->data,
			get_type_name(node->left->type), i + 1,
			node->left->data);
		write_branch(fd, node->left, i + 1);
	}
	if (node->right)
	{
		ft_dprintf(
			fd, "\n    \"%s_%d:\\n%s\" -> \"%s_%d:\\n%s\";",
			get_type_name(node->type), i,
			node->data,
			get_type_name(node->right->type), i + 1,
			node->right->data);
		write_branch(fd, node->right, i + 1);
	}
}

static void	write_ast(int fd, t_ast_node *root)
{
	ft_dprintf(fd, "digraph minishell_parsing {");
	if (!root->left && !root->right)
		write_leaf(fd, root);
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
