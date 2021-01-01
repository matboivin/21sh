/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:58:00 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 21:50:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_lexer.h"

/*
** The lexer adds the current character to the stack
**
** stack: A pointer to the stack
** lexer: The lexer
**
** returns: 0 on success
**          -1 on error
*/

int			push_char(t_lexer *lexer, char **stack)
{
	char	*result;

	result = ft_append_char(*stack, lexer->input + lexer->pos);
	if (!result)
		return (FAIL_RET);
	ft_strdel(stack);
	*stack = result;
	lexer->pos++;
	return (0);
}
