/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:35:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 19:01:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SIGNAL_H
# define SH_SIGNAL_H

# include "sh_define.h"

/*
** Registers signal handlers
*/

void	register_signal_handlers(void);

/*
** Handles SIGINT
*/

void	handle_interrupt(int sig);

#endif
