/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_input_processing.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:21:39 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 21:09:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INPUT_PROCESSING_H
# define SH_INPUT_PROCESSING_H

# include "sh_define.h"
# include "sh_ctrl.h"

/*
** While the shell is not 'done', processes the user input
*/

int		shell_loop(t_shctrl *ft_sh);

/*
** Prompts the user for an input
*/

char	*display_prompt(t_shctrl *ft_sh, const char *prompt);

/*
** Gets the command input
*/

int		process_input(t_shctrl *ft_sh);

#endif
