/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:43:04 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 01:25:59 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_ctype.h"
#include "sh_subsystems.h"

/*
** This function checks an environment variable name format:
** underscores, digits, and ASCII letters, and that begin with a non-digit
*/

size_t		check_var_name(char *s)
{
	size_t	i;

	i = 0;
	if (ft_isdigit(s[i]))
		return (i);
	while ((ft_isalnum(s[i])) || (s[i] == '_'))
		i++;
	return (i);
}
