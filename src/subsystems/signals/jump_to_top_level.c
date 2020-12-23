/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_to_top_level.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:50:59 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 18:52:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include "sh_subsystems.h"

/*
** Exits the program
*/

void	jump_to_top_level(void)
{
	kill(0, SIGUSR1);
}
