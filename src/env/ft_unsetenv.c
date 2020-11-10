/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:04:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 13:32:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include "libft_define.h"
#include "libft_str.h"
#include "sh_env.h"

/*
** This function removes an entry from the environment
** A call to this function is equivalent to a call to ft_putenv when the value
** part of the string is empty.
**
** key: Name of the variable to remove
**
** returns: 0 on success or if key is not found
**          -1 if key is a null pointer, points to an empty string,
**             or points to a string containing an '=' character
*/

int			ft_unsetenv(char *key)
{
	size_t	count;

	if (ft_setenv(key, EMPTY_STR, true) == FAIL_RET)
		return (FAIL_RET);
	count = ft_str_arr_len(g_env);
	g_env = dup_env(count);
	if (!g_env)
		return (FAIL_RET);
	return (0);
}
