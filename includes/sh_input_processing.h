/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_input_processing.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:21:39 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:24:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_INPUT_PROCESSING_H
# define SH_INPUT_PROCESSING_H

# include "sh_define.h"
# include "sh_ctrl.h"

/*
** Main loop
*/

int		shell_loop(t_shctrl *ft_sh);

/*
** Parses the command input
*/

int		parse_command(t_shctrl *ft_sh, char *user_input);

#endif
