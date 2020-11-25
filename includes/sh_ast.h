/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:34:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/25 21:19:14 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_AST_H
# define SH_AST_H

# include "sh_define.h"

/*
** Node types
*/

typedef enum			e_node_type
{
	NODE_TYPE_CMD = 0,
	NODE_TYPE_CMD_NAME,
	NODE_TYPE_CMD_WORD,
	NODE_TYPE_IO_REDIR,
	NODE_TYPE_PIPE_SEQ,
	NODE_TYPE_SIMPLE_CMD
}						t_node_type;

/*
** Abstract Syntax Tree (AST) node
**
** type: The node type
** parent: Pointer to the parent node
** left: Pointer to the left node
** right: Pointer to the right node
** expr: Pointer to the expression (one struct per expression)
*/

typedef struct			s_ast_node
{
	t_node_type			type;
	struct s_ast_node	*parent;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	void				*expr;
}						t_ast_node;

void					create_ast_node(t_ast_node *ast);
t_ast_node				*malloc_ast_node(void);
void					destroy_ast(t_ast_node to_destroy);
void					free_ast(t_ast_node **to_free);

#endif
