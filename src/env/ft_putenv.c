/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:56:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 13:34:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_str.h"
#include "sh_env.h"

/*
** This function appends a new definition to the environment
**
** s: A string of the form ‘name=value’
**
** returns: 0 on success
**          -1 on error
*/

int			ft_putenv(char *s)
{
	size_t	count;

	if (!s || !ft_strchr(s, ENVKEY_SEP))
		return (FAIL_RET);
	count = ft_str_arr_len(g_env);
	g_env = dup_env(count + 1);
	if (!g_env)
		return (FAIL_RET);
	g_env[count] = ft_strdup(s);
	return (0);
}
