/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:24:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/10 14:35:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_subsystems.h"

/*
** This function removes the quotes of word tokens
*/

void		remove_quotes(char **data)
{
	char	*result;
	size_t	len;

	result = NULL;
	if ((**data != STRONG_QUOTE) && (**data != WEAK_QUOTE))
		return ;
	len = ft_strlen(*data) - 2;
	result = ft_substr(*data, 1, len);
	if (result)
		*data = ft_strreplace(*data, result);
	ft_strdel(&result);
}
