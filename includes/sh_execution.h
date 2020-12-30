/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execution.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 22:19:54 by mboivin          ###   ########.fr       */
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
	int			in;
	int			out;
}				t_streams;

/*
** Traverses the AST following the pre-order pattern
*/

void			traverse_tree(t_shctrl *ft_sh, t_ast_node *node);

/*
** Builds a command table for each command node
*/

void			build_cmd_table(t_shctrl *ft_sh);

/*
** Adds a simple command to the command table
*/

void			add_simple_cmd(t_cmd *cmd, t_ast_node *node);

/*
** Counts a simple command arg
*/

void			get_cmd_arg_count(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Retrieves a simple command args
*/

void			get_cmd_args(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Checks whether a file was opened
*/

bool			is_open_file(int fd);

/*
** Opens files for redirections
*/

int				get_files(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Redirections
*/

void			redirect_stream(int from, int to);
void			restore_default_streams(t_streams backup);
void			backup_streams(t_streams *backup);

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
** Retrieves the command filename
*/

size_t			get_cmd_filename(char *cmd_name);

/*
** Check whether the current simple command is a shell builtin
*/

bool			is_builtin(t_simplecmd *simple_cmd);

/*
** Executes all simple commands
*/

void			execute(t_shctrl *ft_sh, t_cmd *cmd);

/*
** This function executes a pipe sequence
*/

void			exec_pipe_seq(t_shctrl *ft_sh, t_cmd *cmd);

/*
** Executes a simple command
*/

void			exec_simple_cmd(t_simplecmd *simple_cmd);

/*
** Invokes a shell builtin
*/

void			invoke_builtin(t_simplecmd *builtin);

/*
** Spawns a new process to execute a simple command
*/

void			spawn_process(t_shctrl *ft_sh, pid_t *pid);

/*
** Creates a pipe object
*/

void			create_pipe(t_shctrl *ft_sh, t_streams *swap);

#endif
