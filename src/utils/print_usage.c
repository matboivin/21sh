/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:50:46 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:41:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "sh_utils.h"

/*
** This function prints the usage message
*/

void	print_usage(char *argv0)
{
	dprintf(STDERR_FILENO, "Usage: %s\n", argv0);
	exit(EXIT_SUCCESS);
}
