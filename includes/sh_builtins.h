/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtins.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:53:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/21 23:19:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTINS_H
# define SH_BUILTINS_H

# include "sh_define.h"

/*
** Builtin env() with no options and no arguments
*/

void	ft_env(int argc, char **argv);

#endif