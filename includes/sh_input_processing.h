/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_input_processing.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:21:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 19:10:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INPUT_PROCESSING_H
# define SH_INPUT_PROCESSING_H

# include "sh_define.h"
# include "sh_ctrl.h"

/*
** While the shell is not 'done', processes the user input
*/

int		wait_for_input(t_shctrl *ft_sh);

/*
** Processes the command input
*/

void	process_input(t_shctrl *ft_sh);

/*
** Gets the command input and splits it into tokens
*/

int		get_command(t_shctrl *ft_sh);

#endif
