/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:08:57 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/29 21:59:50 by mboivin          ###   ########.fr       */
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

int			get_env_len(char *env)
{
	int		i;

	i = 0;
	while (env[i] && env[i] != ENV_VAR_SEP)
		i++;
	return (i);
}

int			ft_findenv(char *key)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!g_env || !key)
		return (FAIL_RET);
	while (g_env && g_env[i])
	{
		len = get_env_len(g_env[i]);
		if (!ft_strncmp(g_env[i], key, len))
			return (i);
		i++;
	}
	return (FAIL_RET);
}
