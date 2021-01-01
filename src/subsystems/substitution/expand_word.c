/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 21:03:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 21:51:55 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_conv.h"
#include "libft_printf.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

void		expand_word(char **tok_word)
{
	// char	*result;

	// result = NULL;
	if (!ft_strchr(*tok_word, BACKSLASH) && !ft_strchr(*tok_word, DOLLAR_SIGN))
		return ;
	substitute_word(tok_word);
	remove_quotes(tok_word);
}
