/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ast_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 18:05:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	print_node(int fd, t_ast_node *node)
{
	if (node->data)
		ft_dprintf(fd, "\n    \"%s\\n%p\"", node->data, node);
	else
		ft_dprintf(fd, "\n    \"%s\\n%p\"", get_type_name(node->type), node);
}

static void	print_node_next(int fd, t_ast_node *node)
{
	if (node->data)
		ft_dprintf(fd, " -> \"%s\\n%p\";", node->data, node);
	else
		ft_dprintf(fd, " -> \"%s\\n%p\";", get_type_name(node->type), node);
}

static void	print_leaf(int fd, char side, int count)
{
	ft_dprintf(fd, " -> leaf_%c_%d;", side, count);
	ft_dprintf(fd, "\n    leaf_%c_%d [shape=plain];", side, count);
}

static void	write_branch(int fd, t_ast_node *node)
{
	static int	count = 0;

	print_node(fd, node);
	if (node->left)
	{
		print_node_next(fd, node->left);
		write_branch(fd, node->left);
	}
	else if (!node->left && node->right)
		print_leaf(fd, 'L', count++);
	print_node(fd, node);
	if (node->right)
	{
		print_node_next(fd, node->right);
		write_branch(fd, node->right);
	}
	else if (!node->right && node->left)
		print_leaf(fd, 'R', count++);
}

void		write_ast_dot(int fd, t_ast_node *root)
{
	ft_dprintf(fd, "digraph minishell_parsing {");
	if (!root->left && !root->right)
		ft_dprintf(fd, "\n    \"%s\";", root->data);
	else
		write_branch(fd, root);
	ft_dprintf(fd, "\n}");
}
