/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 18:24:50 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/09 18:31:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_subsystems.h"

/*
** This function removes the quotes of word tokens
*/

void			remove_quotes(char **data)
{
	const char	*set = "\"\'";
	char		*result;

	result = NULL;
	if ((**data != STRONG_QUOTE) && (**data != WEAK_QUOTE))
		return ;
	result = ft_strtrim(*data, set);
	if (result)
		*data = ft_strreplace(*data, result);
	ft_strdel(&result);
}
