/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:03:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 16:58:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_expr.h"
#include "sh_ast.h"

/*
** Abstract Syntax Tree (AST)
**
** create_tree_root()  :  Malloc and construct root node
** create_ast_node()   :  Constructor
** malloc_ast_node()   :  Malloc function
** destroy_ast()       :  Destructor
** free_ast()          :  Free function
*/

void			create_tree_root(t_ast_node **root)
{
	*root = malloc_ast_node(
		NODE_PROGRAM,
		NULL);
}

t_ast_node		create_ast_node(t_node_type p_type, char *p_data)
{
	t_ast_node	result;

	result.type = p_type;
	result.left = NULL;
	result.right = NULL;
	result.data = p_data;
	return (result);
}

t_ast_node		*malloc_ast_node(t_node_type p_type, char *p_data)
{
	t_ast_node	*result;

	result = malloc(sizeof(t_ast_node));
	if (!result)
		return (NULL);
	*result = create_ast_node(p_type, p_data);
	return (result);
}

void			destroy_ast(t_ast_node to_destroy)
{
	if (to_destroy->data)
		ft_strdel(to_destroy->data);
}

void			free_ast(t_ast_node **to_free)
{
	if (*to_free && to_free)
	{
		free_ast(&(*to_free)->left);
		free_ast(&(*to_free)->right);
		destroy_ast(**to_free);
		free(*to_free);
		*to_free = NULL;
	}
}
