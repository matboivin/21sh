/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:04:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 21:04:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sh_lexer.h"

/*
** This function checks whether the lexer is full
*/

bool	lexer_is_full(t_lexer *lexer)
{
	return (lexer->size == lexer->capacity);
}
