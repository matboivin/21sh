/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expansion.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:07:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXPANSION_H
# define SH_EXPANSION_H

# include <stdbool.h>
# include <unistd.h>
# include "sh_define.h"
# include "sh_ast.h"
# include "sh_command.h"
# include "sh_ctrl.h"

/*
** Traverses the AST following the pre-order pattern
*/

void	traverse_tree(t_shctrl *ft_sh, t_ast_node *node);

/*
** Builds a command table for each command node
*/

void	build_cmd_table(t_shctrl *ft_sh);

/*
** Adds a simple command to the command table
*/

void	add_simple_cmd(t_cmd *cmd, t_ast_node *node);

/*
** Counts a simple command arg
*/

void	get_cmd_arg_count(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Retrieves a simple command args
*/

void	get_cmd_args(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Checks whether a file was opened
*/

bool	is_open_file(int fd);

/*
** Opens files for redirections
*/

int		get_files(t_simplecmd *simple_cmd, t_ast_node *node);

/*
** Searches the command to run
*/

int		search_command(t_simplecmd *simple_cmd);

/*
** Searches the command in the list of builtins
*/

void	search_builtin(t_simplecmd *simple_cmd);

/*
** Checks whether the command path contains any slashes
*/

bool	contain_slash(char *cmd_path);

/*
** Retrieves the command filename
*/

size_t	get_cmd_filename(char *cmd_name);

/*
** Expands a word
*/

void	expand_word(char **tok_word);

#endif
