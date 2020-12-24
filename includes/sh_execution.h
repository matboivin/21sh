/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/24 17:52:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXECUTION_H
# define SH_EXECUTION_H

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include "sh_define.h"
# include "sh_ast.h"
# include "sh_command.h"
# include "sh_ctrl.h"

typedef struct	s_streams
{
	int			input;
	int			output;
}				t_streams;

/*
** Traverses the AST following the pre-order pattern
*/

void			traverse_tree(t_shctrl *ft_sh, t_ast_node *node);

/*
** Visits an AST node
*/

void			visit(t_shctrl *ft_sh, t_ast_node *node);

/*
** Builds a command table for each command node
*/

void			build_cmd_table(t_shctrl *ft_sh);

/*
** Adds a simple command to the command table
*/

int				add_simple_cmd(t_cmd *cmd, t_ast_node *node);

/*
** Counts a simple command arg
*/

void			get_cmd_arg_count(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Retrieves a simple command args
*/

void			get_cmd_args(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Checks whether the current simple command is the last one
*/

bool			is_last_command(t_cmd *cmd);

/*
** Checks whether a file was opened
*/

bool			is_open_file(int fd);

/*
** Redirections
*/

void			get_files(t_simplecmd *simple_cmd, t_ast_node *node);
void			redirect_stream(int from, int to);

/*
** Searches the command to run
*/

int				search_command(t_simplecmd *simple_cmd);

/*
** Searches the command in the list of builtins
*/

void			search_builtin(t_simplecmd *simple_cmd);

/*
** Checks whether the command path contains any slashes
*/

bool			contain_slash(char *cmd_path);

/*
** Executes all simple commands
*/

void			execute(t_shctrl *ft_sh, t_cmd *cmd);

/*
** Executes a simple command
*/

void			exec_simple_cmd(t_shctrl *ft_sh, t_simplecmd *simple_cmd);

/*
** Spawns a new process
*/

void			spawn_process(t_shctrl *ft_sh, pid_t *pid);
void			create_pipe(t_shctrl *ft_sh, t_streams *swap);

#endif
