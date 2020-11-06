/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:53:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:00:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <stddef.h>

/*
** Simple command
*/

typedef struct	s_simplecmd
{
	size_t		argc;
	char		**cmd_args;
}				t_simplecmd;

t_simplecmd		*malloc_simple_command(void);
void			get_command_args(t_simplecmd *simple_cmd, char *args);
void			free_command(t_simplecmd *to_free);
void			print_command_args(t_simplecmd *simple_cmd);

/*
** Command
*/

typedef struct	s_cmd
{
	size_t		capacity;
	size_t		cmd_count;
	t_simplecmd	**simple_cmds;
	char		*input_file;
	char		*output_file;
}				t_cmd;

t_cmd			*malloc_cmd_table(size_t p_capacity);
void			free_cmd_table(t_cmd *to_free);
void			print_cmd_table(t_cmd *cmds);

#endif
