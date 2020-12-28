/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:53:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 14:51:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

# include "sh_define.h"

/*
** Recoded builtin cd() with only a relative or absolute path
*/

int		cd_builtin(int argc, char **argv);

/*
** Recoded builtin echo() with option ’-n’
*/

int		echo_builtin(int argc, char **argv);

/*
** Recoded builtin env() with no options and no arguments
*/

int		env_builtin(int argc, char **argv);

/*
** Recoded builtin exit() without any options
*/

int		exit_builtin(int argc, char **argv);

/*
** Recoded builtin export() without any options
*/

int		export_builtin(int argc, char **argv);

/*
** Displays all exported variables
*/

int		display_export(void);

/*
** Recoded builtin pwd() without any options
*/

int		pwd_builtin(int argc, char **argv);

/*
** Recoded builtin unset() without any options
*/

int		unset_builtin(int argc, char **argv);

#endif
