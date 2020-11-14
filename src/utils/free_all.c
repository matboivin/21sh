/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:22:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:20:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_env.h"
#include "sh_ctrl.h"
#include "sh_utils.h"

/*
** This function frees the allocated memory
*/

void	free_all(t_shctrl *ft_sh)
{
	ft_clearenv();
	destroy_shell(ft_sh);
}
