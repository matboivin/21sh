/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:03:49 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/26 16:13:48 by mboivin          ###   ########.fr       */
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

void			create_ast_node(t_ast_node *ast)
{
	ast->type = 0;
	ast->left = NULL;
	ast->right = NULL;
	ast->expr = NULL;
}

t_ast_node		*malloc_ast_node(void)
{
	t_ast_node	*result;

	result = malloc(sizeof(t_ast_node));
	if (!result)
		return (NULL);
	create_ast_node(result);
	return (result);
}

void			destroy_ast(t_ast_node to_destroy)
{
	(void)to_destroy;
}

void			free_ast(t_ast_node **to_free)
{
	if (to_free)
	{
		free(*to_free);
		*to_free = NULL;
	}
}
