/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:53:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 00:51:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

# include "sh_define.h"

/*
** Recoded builtin cd() with only a relative or absolute path
*/

void	ft_cd(int argc, char **argv);

/*
** Recoded builtin echo() with option ’-n’
*/

void	ft_echo(int argc, char **argv);

/*
** Recoded builtin env() with no options and no arguments
*/

void	ft_env(int argc, char **argv);

/*
** Recoded builtin exit() without any options
*/

void	ft_exit(int argc, char **argv);

/*
** Recoded builtin export() without any options
*/

void	ft_export(int argc, char **argv);

/*
** Recoded builtin pwd() without any options
*/

void	ft_pwd(int argc, char **argv);

/*
** Recoded builtin pwd() without any options
*/

void	ft_pwd(int argc, char **argv);

/*
** Recoded builtin unset() without any options
*/

void	ft_unset(int argc, char **argv);

#endif
