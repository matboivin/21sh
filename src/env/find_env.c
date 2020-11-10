/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:08:57 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 13:34:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_env.h"

/*
** This function searches for the environment variable which name is key
**
** key: Name of the variable to search
**
** returns: The index of the variable
**          -1 otherwise
*/

int		find_env(char *key)
{
	int	i;

	if (!g_env || !key)
		return (FAIL_RET);
	i = 0;
	while (g_env && g_env[i])
	{
		if (ft_strcmp(g_env[i], key) == ENVKEY_SEP)
			return (i);
		i++;
	}
	return (FAIL_RET);
}
