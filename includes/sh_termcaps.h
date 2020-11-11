/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_termcaps.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:18:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 19:46:30 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_TERMCAPS_H
# define SH_TERMCAPS_H

# include "sh_define.h"

/*
** Looks for the terminal type and loads the corresponding termcaps
*/

void	init_term_data(void);

#endif
