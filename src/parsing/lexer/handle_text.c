/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:08 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/22 19:19:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_lexer.h"

void	handle_text(t_lexer *lexer, char **stack)
{
	add_token_to_lexer(lexer, *stack, ft_strlen(*stack), TOKEN_WORD);
	ft_strdel(stack);
}
