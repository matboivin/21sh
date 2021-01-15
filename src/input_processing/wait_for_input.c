/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/15 22:06:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_utils.h"
#include "wandre_mode.h"
#include "sh_input_processing.h"

/*
** While the shell is not 'done', processes the user input: a command
**   Prompt the user for an input
**   Parse the command
**   Execute the command
**   Return status
*/

int		wait_for_input(t_shctrl *ft_sh)
{
	while (!g_done)
		process_input(ft_sh);
	free_all(ft_sh);
#ifdef DEBUG
	ft_printf(
		"\n----------- DEBUG: STATUS -----------\nexited with: %d\n", g_status);
#endif /* DEBUG */
#ifdef WANDRE_MODE
	ft_printf("%sbye :)\n\n", WANDRE_PREFIX);
#endif /* WANDRE_MODE */
	return (g_status);
}
