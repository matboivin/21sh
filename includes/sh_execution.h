/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 17:01:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXECUTION_H
# define SH_EXECUTION_H

# include <stdbool.h>
# include "sh_define.h"
# include "sh_ast.h"

/*
** Simple command
**
** argc: The number of arguments
** cmd_args: The simple command name (cmd_args[0]) followed by arguments
** input_file: filename (default: NULL)
** output_file: filename (default: NULL)
*/

typedef struct	s_simplecmd
{
	size_t		argc;
	char		**cmd_args;
	char		*input_file;
	char		*output_file;
}				t_simplecmd;

/*
** Command
**
** capacity: Maximum capacity of the command
** cmd_count: The number of simple commands
** simple_cmds: The simple commands contained in the command
*/

typedef struct	s_cmd
{
	size_t		capacity;
	size_t		cmd_count;
	t_simplecmd	**simple_cmds;
}				t_cmd;

/*
** Simple command
**
** malloc_simple_cmd()  :  Malloc function
** free_simple_cmd()    :  Free function
** print_simple_cmd()   :  Debug
*/

t_simplecmd		*malloc_simple_cmd(void);
void			free_simple_cmd(t_simplecmd *to_free);
void			print_simple_cmd(t_simplecmd *simple_cmd);

/*
** Command
**
** malloc_cmd()   :  Malloc function
** destroy_cmd()  :  Destructor
** free_cmd()     :  Free function
** print_cmd()    :  Debug
*/

t_cmd			*malloc_cmd(size_t p_capacity);
void			destroy_cmd(t_cmd to_destroy);
void			free_cmd(t_cmd **to_free);
void			print_cmd(t_cmd *cmds);

/*
** Visits an AST node
*/

void			visit(t_ast_node *node);

/*
** Traverses the AST following the in-order pattern
*/

void			traverse_tree(t_ast_node *node);

/*
** Checks whether the current simple command is the last one
*/

bool			is_last_command(size_t cmd_i, size_t cmd_count);

#endif
