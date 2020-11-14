/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 22:00:02 by mboivin          ###   ########.fr       */
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
void	print_match_error(char c);

/*
** Frees all the allocated memory
*/

void	free_all(t_shctrl *ft_sh);

/*
** Frees all the allocated memory and exits with the status passed as parameter
*/

void	exit_ft_sh(int status, t_shctrl *ft_sh);

#endif
