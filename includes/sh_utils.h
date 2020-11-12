/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 18:23:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_UTILS_H
# define SH_UTILS_H

# include "sh_define.h"

/*
** Prints the usage message
*/

void	print_usage(void);

/*
** Frees the allocated memory
*/

void	free_all(void);

/*
** Frees the allocated memory and exits with the status passed as parameter
*/

void	exit_ft_sh(int status);

/*
** Prints and error messages, frees the allocated memory and exits with 1
*/

void	exit_error(char *target);

#endif
