/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:00:03 by mboivin          ###   ########.fr       */
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
** Frees all the allocated memory
*/

void	free_all(t_shctrl *ft_sh);

/*
** Frees all the allocated memory and exits with the status passed as parameter
*/

void	exit_ft_sh(int status, t_shctrl *ft_sh);

/*
** Prints an error message, frees all the allocated memory and exits with 1
*/

void	exit_error(char *target, t_shctrl *ft_sh);

#endif
