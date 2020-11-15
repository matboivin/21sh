/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_ft_sh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 14:47:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/15 14:45:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_printf.h"
#include "sh_utils.h"

/*
** This function frees the allocated memory and exits with the status passed as
** parameter
*/

void	exit_ft_sh(int status, t_shctrl *ft_sh)
{
	free_all(ft_sh);
#ifdef DEBUG
	ft_printf(
		"\n----------- DEBUG: STATUS -----------\nexited with: %d\n", g_status);
#endif /* DEBUG */
	exit(status);
}
