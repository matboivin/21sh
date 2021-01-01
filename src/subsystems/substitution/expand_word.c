/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:03:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 00:07:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_conv.h"
#include "libft_printf.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

// Tant qu'il y a des char
// Si pas de quotes ou weak quote, substitution == True
// Si le char est un backslash -> escape
// Si le char est une quote -> Retirer les quotes
// Si le char est un dollar et substitution == True -> Remplacer par valeur
// Sinon, empiler char

void		expand_word(char **tok_word)
{
	char	*result;
	size_t	i;
	size_t	len;
	bool	replace;

	result = NULL;
	i = 0;
	len = 0;
	replace = true;
	if (**tok_word == STRONG_QUOTE)
		replace = false;
	if (!ft_strchr(*tok_word, BACKSLASH) && !ft_strchr(*tok_word, DOLLAR_SIGN))
		return ;
	len = ft_strlen(*tok_word);
	while (i < len)
	{
		if ((*tok_word)[i] == BACKSLASH)
		{
			i++;
			result = ft_append_char(result, *tok_word + i, true);
		}
		else if (((*tok_word)[i] == DOLLAR_SIGN) && replace)
			substitute_var(&result, *tok_word, &i);
		else
			result = ft_append_char(result, *tok_word + i, true);
		i++;
	}
	if (result)
		*tok_word = ft_strreplace(*tok_word, result);
	ft_strdel(&result);
	//remove_quotes(tok_word);
}
