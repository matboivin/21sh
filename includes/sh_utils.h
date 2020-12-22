/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 00:13:01 by mboivin          ###   ########.fr       */
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
** Error messages
*/

void	print_error(char *target, const char *msg);
void	print_errno(char *target);
void	handle_syntax_error(const char *token);
void	handle_matching_error(char c);
void	print_builtin_error(char *cmd_name, char *target, const char *msg);
void	handle_cmd_not_found(char *filename);

/*
** Frees all the allocated memory
*/

void	free_all(t_shctrl *ft_sh);

/*
** Frees all the allocated memory and exits
*/

void	exit_shell(t_shctrl *ft_sh);

#endif
