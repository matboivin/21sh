/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:08:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/29 18:01:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_ctype.h"
#include "sh_env.h"

/*
** This function checks whether an environment variable name begins by a letter
** or by an underscore, and not by an equal sign
*/

int		is_valid_identifier(char *s)
{
	int	i;

	i = 0;
	if (s[i] == ENV_VAR_SEP)
		return (0);
	while (s[i])
	{
		if ((!ft_isalpha(s[i])) || (s[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}
