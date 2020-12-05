/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:16:42 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 18:02:09 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_lexer.h"

static t_regex	g_regex_list[] =
{
	{ "&&", 2, TOKEN_AND_IF },
	{ "||", 2, TOKEN_OR_IF },
	{ ">>", 2, TOKEN_DGREAT },
	{ "//", 1, TOKEN_BACKSLASH },
	{ "\n", 1, TOKEN_NEWLINE },
	{ "|", 1, TOKEN_PIPE },
	{ ">", 1, TOKEN_GREAT },
	{ "<", 1, TOKEN_LESS },
	{ ";", 1, TOKEN_SEMI },
	{ " ", 1, TOKEN_EAT },
	{ "\v", 1, TOKEN_EAT },
	{ "\t", 1, TOKEN_EAT },
	{ "\r", 1, TOKEN_EAT },
	{ "\f", 1, TOKEN_EAT },
	{ NULL, 0, TOKEN_NOT_FOUND }
};

/*
** This function searches if input is a token
*/

t_regex		get_token(char *input)
{
	int		i;

	i = 0;
	while (i < MAX_TOKENS)
	{
		if (!ft_strncmp(g_regex_list[i].op, input, g_regex_list[i].len))
			return (g_regex_list[i]);
		i++;
	}
	return (g_regex_list[TOKEN_NOT_FOUND]);
}
