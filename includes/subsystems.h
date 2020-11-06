/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsystems.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:16:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 18:51:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSYSTEMS_H
# define SUBSYSTEMS_H

# include <signal.h>
# include "ft_define.h"

extern volatile sig_atomic_t	g_done;

int		listen(void);

void	register_signal_handlers(void);
void	signal_handler(int sig);

#endif