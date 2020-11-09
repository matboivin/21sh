/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:04:05 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 18:14:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"

/*
** This function removes all entries from the environment
*/

void	ft_clearenv(void)
{
	if (!g_env)
		return ;
	ft_str_arr_del(g_env);
}
