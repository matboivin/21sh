/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/01 19:08:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_ast.h"

/*
** This function creates a dot graph from a given Abstract Syntax Tree (AST)
*/

static char	*get_type_name(t_node_type n)
{
	char	*node_names[6];

	node_names[NODE_PROGRAM] = "Program";
	node_names[NODE_CMD] = "Command";
	node_names[NODE_WORD] = "Word";
	node_names[NODE_IO_FILE] = "IO File";
	node_names[NODE_PIPE_SEQ] = "Pipe sequence";
	node_names[NODE_SIMPLE_CMD] = "Simple Command";
	return (node_names[n]);
}

static void	write_leaf(int fd, t_ast_node *node)
{
	ft_dprintf(fd, "\n    \"%s\";", get_type_name(node->type));
}

static void	write_branch(int fd, t_ast_node *node, int i)
{
	if (node->left)
	{
		ft_dprintf(
			fd, "\n    \"%s%d\" -> \"%s%d\";",
			get_type_name(node->type), i,
			get_type_name(node->left->type), i + 1
			);
		write_branch(fd, node->left, i + 1);
	}
	if (node->right)
	{
		ft_dprintf(
			fd, "\n    \"%s%d\" -> \"%s%d\";",
			get_type_name(node->type), i,
			get_type_name(node->right->type), i+ 1
			);
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

void		print_ast(t_ast_node *root)
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
