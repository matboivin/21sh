/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:03:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 18:59:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_ast.h"

/*
** Abstract Syntax Tree (AST)
**
** create_ast_node()  :  Constructor
** malloc_ast_node()  :  Malloc function
** destroy_ast()      :  Destructor
** free_ast()         :  Free function
*/

t_ast_node		create_ast_node(
	t_node_type p_type, t_ast_node *p_left, t_ast_node *p_right, void *p_expr)
{
	t_ast_node	result;

	result.type = p_type;
	result.left = p_left;
	result.right = p_right;
	result.expr = p_expr;
	return (result);
}

t_ast_node		*malloc_ast_node(
	t_node_type p_type, t_ast_node *p_left, t_ast_node *p_right, void *p_expr)
{
	t_ast_node	*result;

	result = malloc(sizeof(t_ast_node));
	if (!result)
		return (NULL);
	*result = create_ast_node(p_type, p_left, p_right, p_expr);
	return (result);
}

void			destroy_ast(void *to_destroy)
{
	(void)to_destroy;
}

void			free_ast(t_ast_node *to_free)
{
	if (to_free)
	{
		free_ast(to_free->left);
		free_ast(to_free->right);
		destroy_ast(to_free->expr);
		free(to_free);
		to_free = NULL;
	}
}
