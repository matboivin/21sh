/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:08:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/29 22:50:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_ctype.h"
#include "sh_env.h"

/*
** This function checks an environment variable name format:
** underscores, digits, and ASCII letters, and that begin with a non-digit
*/

int		is_valid_identifier(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == ENV_VAR_SEP) || (ft_isdigit(s[i])))
		return (0);
	while (s[i] && (s[i] != ENV_VAR_SEP))
	{
		if ((!ft_isalnum(s[i])) && (s[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}
