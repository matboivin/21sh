/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:08:57 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:28:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"
#include "sh_env.h"

/*
** This function calculates the length of an environment variable
**
** key: Name of the variable
**
** returns: The length of the variable
*/

int			get_env_len(char *key)
{
	size_t	len;

	len = 0;
	if (ft_isdigit(key[len]))
		return (1);
	while ((ft_isalnum(key[len])) || (key[len] == '_'))
		len++;
	return (len);
}
