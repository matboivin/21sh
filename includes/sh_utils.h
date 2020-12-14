/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 16:11:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_UTILS_H
# define SH_UTILS_H

# include "sh_define.h"
# include "sh_ctrl.h"

/*
** Prints the usage message
*/

void	print_usage(void);

/*
** Syntax errors
*/

void	print_syntax_error(const char *token);
void	print_matching_error(char c);

/*
** Frees all the allocated memory
*/

void	free_all(t_shctrl *ft_sh);

/*
** Frees all the allocated memory and exits
*/

void	exit_shell(t_shctrl *ft_sh);

void	exit_error(t_shctrl *ft_sh, char *target);

#endif
