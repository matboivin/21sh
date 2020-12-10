/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/10 18:59:43 by mboivin          ###   ########.fr       */
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

static void	write_leaf(int fd, t_ast_node *node)
{
	ft_dprintf(
		fd, "\n    \"%s\";", node->data);
}

static void	write_branch(int fd, t_ast_node *node, int i)
{
	if (node->left)
	{
		while (!node->data && node->left)
			node = node->left;
		ft_dprintf(fd, "\n    \"%s\\n%d\"", node->data, i);
		while (!node->left->data && node->left->left)
			node->left = node->left->left;
		if (node->left->data)
			ft_dprintf(fd, " -> \"%s\\n%d\";", node->left->data, i + 1);
		else
			ft_dprintf(fd, ";");
		write_branch(fd, node->left, i + 1);
	}
	if (node->right)
	{
		while (!node->data && node->right)
			node = node->right;
		ft_dprintf(fd, "\n    \"%s\\n%d\"", node->data, i);
		while (!node->right->data && node->right->right)
			node->right = node->right->right;
		if (node->right->data)
			ft_dprintf(fd, " -> \"%s\\n%d\";", node->right->data, i + 1);
		else
			ft_dprintf(fd, ";");
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
