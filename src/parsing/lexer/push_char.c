/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:58:00 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 23:11:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
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
	*stack = ft_append_char(*stack, lexer->input + lexer->pos, true);
	if (!(*stack))
		return (FAIL_RET);
	lexer->pos++;
	return (0);
}
