/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:54:10 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/26 21:21:40 by mboivin          ###   ########.fr       */
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

static void		write_ast(int fd, t_ast_node *root)
{
	t_ast_node	*cursor;

	cursor = root;
	ft_dprintf(fd, "\n    \"%s\"", cursor->data);
	while (cursor->right)
	{
		cursor = cursor->right;
		ft_dprintf(fd, " -> \"%s\"", cursor->data);
	}
	ft_dprintf(fd, ";");
}

void			print_ast(t_ast_node *root)
{
	int			fd;

	if (!root)
		return ;
	fd = open(AST_DOT_FILE, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	if (!fd)
		exit(EXIT_FAILURE);
	ft_dprintf(fd, "digraph minishell_parsing {");
	write_ast(fd, root);
	ft_dprintf(fd, "\n}");
	close(fd);
}
