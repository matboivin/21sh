/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:53:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/10/01 14:10:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

/*
** Command structure
*/

typedef struct	s_cmd
{
	int			argc;
	int			simple_cmds_count;
	char		**simple_cmds; // TODO: construct simple command
	char		*outfile; // NULL if no redirection, otherwise name of the file
	char		*infile; // NULL if no redirection, otherwise name of the file
}				t_cmd;

// TODO:
// Creator, destructor
// function to insert a simple command, function to execute command
// Static variable for current command?

#endif
