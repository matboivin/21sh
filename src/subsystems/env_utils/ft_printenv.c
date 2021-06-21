/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:44:39 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/21 17:47:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft_str.h"
#include "sh_env.h"

/*
** This function prints name and value pairs for all environment variables
*/

int			ft_printenv(void)
{
	size_t	i;

	if (!g_env)
		return (EXIT_FAILURE);
	i = 0;
	while (g_env[i])
	{
		if (ft_strchr(g_env[i], ENV_VAR_SEP))
			printf("%s\n", g_env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
