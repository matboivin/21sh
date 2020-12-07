/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:10:12 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/07 17:13:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_printf.h"
#include "libft_ctype.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function substitutes the variable name by its value
*/

void		substitute_word(char **data)
{
	char	*result;
	char	*dollar_sign;
	size_t	start;
	size_t	len;

	if (**data == STRONG_QUOTE)
		return ;
	result = NULL;
	dollar_sign = NULL;
	len = 0;
	if ((dollar_sign = ft_strchr(*data, DOLLAR_SIGN)))
	{
		dollar_sign++;
		start = dollar_sign - *data;
		while (ft_isalnum(dollar_sign[len]) || dollar_sign[len] == '_')
			len++;
		result = ft_getenv(ft_substr(*data, start, len));
		ft_printf("%s\n", result);
	}
}
