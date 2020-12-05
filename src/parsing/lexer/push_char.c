/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:58:00 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 18:03:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"

/*
** The lexer adds the current character to the stack
**
** stack: A pointer to the stack
** c: A pointer to the char to add
**
** returns: The new stack
**          NULL otherwise
*/

char		*push_char(char *stack, char **c)
{
	char	*result;
	size_t	len_stack;
	size_t	len;

	len_stack = 0;
	if (stack)
		len_stack = ft_strlen(stack);
	len = len_stack + 1;
	result = ft_strnew(len);
	if (!result)
		return (NULL);
	if (stack)
	{
		ft_strlcpy(result, stack, (len_stack + 1));
		ft_strdel(&stack);
	}
	ft_strlcpy(result + len_stack, *c, 2);
	(*c)++;
	return (result);
}
