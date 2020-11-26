/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:34:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/26 21:31:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_AST_H
# define SH_AST_H

# include "sh_define.h"

# define FILE_PERMISSIONS 0644
# define AST_DOT_FILE "ast.dot"

/*
** Node types
*/

typedef enum			e_node_type
{
	NODE_TYPE_CMD = 0,
	NODE_TYPE_WORD,
	NODE_TYPE_IO_REDIR,
	NODE_TYPE_PIPE_SEQ,
	NODE_TYPE_SIMPLE_CMD
}						t_node_type;

/*
** Abstract Syntax Tree (AST) node
**
** type: The node type
** left: Pointer to the left node
** right: Pointer to the right node
** expr: Pointer to the expression (one struct per expression)
*/

typedef struct			s_ast_node
{
	t_node_type			type;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	char				*data;
}						t_ast_node;

t_ast_node				create_ast_node(
	t_node_type p_type, t_ast_node *p_left, t_ast_node *p_right, char *p_data);
t_ast_node				*malloc_ast_node(
	t_node_type p_type, t_ast_node *p_left, t_ast_node *p_right, char *p_data);
void					free_ast(t_ast_node *to_free);
void					print_ast(t_ast_node *root);

#endif
