/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:47:20 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/24 17:52:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sh_execution.h"

/*
** This function checks whether a file was opened
*/

bool	is_open_file(int fd)
{
	return (fd != NO_FILE);
}
