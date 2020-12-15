/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_last_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:33:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:37:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sh_execution.h"

/*
** This function checks whether the current simple command is the last one
*/

bool	is_last_command(size_t i, size_t cmd_count)
{
	return (i == (cmd_count - 1));
}
