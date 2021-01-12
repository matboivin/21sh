/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:34:29 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 18:18:57 by mboivin          ###   ########.fr       */
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
	NODE_PROGRAM = 0,
	NODE_CMD,
	NODE_CMD_SUFFIX,
	NODE_IO_FILE,
	NODE_PIPE_SEQ,
	NODE_SIMPLE_CMD,
	NODE_WORD
}						t_node_type;

/*
** Abstract Syntax Tree (AST) node
**
** type: The node type
** left: Pointer to the left node
** right: Pointer to the right node
** data: The node data
*/

typedef struct			s_ast_node
{
	t_node_type			type;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	char				*data;
}						t_ast_node;

/*
** Abstract Syntax Tree (AST)
**
** create_tree_root()  :  Malloc and construct root node
** create_ast_node()   :  Constructor
** malloc_ast_node()   :  Malloc function
** free_ast()          :  Free function
*/

void		create_tree_root(t_ast_node **root);
t_ast_node	create_ast_node(t_node_type p_type, char *p_data);
t_ast_node	*malloc_ast_node(t_node_type p_type, char *p_data);
void		free_ast(t_ast_node **to_free);

/*
** Debug
*/

void		print_ast(t_ast_node *root);
void		save_ast_svg(void);
void		save_ast_dot(t_ast_node *root);
void		write_ast_dot(int fd, t_ast_node *root);

/*
** Adds a leaf node to the left of the tree
*/

void		append_node_left(t_ast_node **node, t_ast_node *new_node);

/*
** Adds a leaf node to the right of the tree
*/

void		append_node_right(t_ast_node **node, t_ast_node *new_node);

#endif
