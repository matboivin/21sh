/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_command.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:09:32 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 17:10:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_COMMAND_H
# define SH_COMMAND_H

# include "sh_define.h"

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

#endif
