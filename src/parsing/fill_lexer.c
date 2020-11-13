/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 21:07:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_printf.h"
#include "sh_lexer.h"

void			fill_lexer(char *input, t_lexer *lexer)
{
	t_regex		current_regex;
	//const char*	prev;

	(void)lexer;
	//prev = input;
	while (input && *input)
	{
		current_regex = get_token_type(input);
		if (current_regex.type)
		{
			ft_printf("Regex: %s\n", current_regex.op);
			input += current_regex.len;
		}
		else
		{
			ft_printf("Input: %s\n", input);
			input += ft_strlen(input);
		}
	}
}
