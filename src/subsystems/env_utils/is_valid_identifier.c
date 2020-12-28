/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:08:34 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 15:16:15 by mboivin          ###   ########.fr       */
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
	return (((ft_isalpha(s[0])) || (s[0] == '_')) && (s[0] != ENVKEY_SEP));
}
