/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/25 21:59:41 by mboivin          ###   ########.fr       */
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

void	print_error(int count, ...);
void	print_errno(char *target);
void	handle_syntax_error(const char *token);
void	handle_matching_error(char c);
void	handle_cmd_not_found(char *filename);

/*
** Builtins error messages
*/

int		handle_arg_err(char *cmd_name);
int		handle_invalid_id(char *cmd_name, char *var_name);

/*
** Frees all the allocated memory
*/

void	free_all(t_shctrl *ft_sh);

/*
** Frees all the allocated memory and exits
*/

void	exit_shell(t_shctrl *ft_sh);

#endif
