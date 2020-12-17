/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fatal_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:52:28 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/17 19:15:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function handles fatal errors
**
** The return value of a command is its exit status, or 128 + N if the command
** is terminated by signal N
*/

void	handle_fatal_error(int sig)
{
	if (sig == SIGINT)
	{
		g_status = FATAL_ERROR + sig;
		ft_printf("\n%s", ft_getenv("PS1"));
	}
}
