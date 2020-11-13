/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 23:16:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_printf.h"
#include "sh_lexer.h"

// static int		raise_syntax_error(const char *token)
// {
// 	ft_dprintf(
// 		STDERR_FILENO,
// 		"syntax error near unexpected token `%s'\n",
// 		token);
// 	return (FAIL_RET);
// }

int				fill_lexer(char *input, t_lexer *lexer)
{
	t_regex		found;
	//t_regex	prev;

	while (input && *input)
	{
		found = get_token_type(input);
		if (found.type && found.type == TOKEN_EAT)
			input++;
		else if (found.type)
		{
			if (found.type == TOKEN_BACKSLASH)
			{
				//TODO: handle escaping
				ft_printf("Regex: %s\n", found.op);
			}
			else
			{
				ft_printf("Regex: %s\n", found.op);
				add_token_to_lexer(lexer, found.op, found.len, found.type);
			}
			input += found.len;
		}
		else
		{
			ft_printf("Input: %s\n", input);
			add_token_to_lexer(lexer, input, ft_strlen(input), TOKEN_TEXT);
			input += ft_strlen(input);
		}
	}
	return (0);
}
