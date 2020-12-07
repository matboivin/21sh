/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:44:39 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 16:04:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_printf.h"
#include "sh_env.h"

/*
** This function prints name and value pairs for all environment variables
*/

void		ft_printenv(void)
{
	size_t	i;

	if (!g_env)
		return ;
	i = 0;
	while (g_env[i])
		ft_printf("%s\n", g_env[i++]);
}
