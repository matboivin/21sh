/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/28 20:19:56 by mboivin          ###   ########.fr       */
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

static void	write_leaf(int fd, t_ast_node *node)
{
	ft_dprintf(fd, "\n    \"%s\";", node->data);
}

static void	write_branch(int fd, t_ast_node *node)
{
	if (node->left)
	{
		ft_dprintf(
			fd, "\n    \"%s\" -> \"%s\";", node->data, node->left->data);
		write_branch(fd, node->left);
	}
	else
		write_leaf(fd, node);
	if (node->right)
	{
		ft_dprintf(
			fd, "\n    \"%s\" -> \"%s\";", node->data, node->right->data);
		write_branch(fd, node->right);
	}
	else
		write_leaf(fd, node);
}

static void	write_ast(int fd, t_ast_node *root)
{
	ft_dprintf(fd, "digraph minishell_parsing {");
	if (!root->left && !root->right)
		write_leaf(fd, root);
	else
		write_branch(fd, root);
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
