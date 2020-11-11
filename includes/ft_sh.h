/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 14:16:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "sh_define.h"
# include "sh_env.h"
# include "sh_input_processing.h"
# include "sh_signal_handling.h"
# include "sh_builtin.h"

/*
** Utils
*/

void	print_usage(void);
void	print_error(char *target);
void	exit_error(char *target);

#endif
