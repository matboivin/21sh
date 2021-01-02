/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 00:36:06 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 00:36:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sh_subsystems.h"

/*
** This function checks whether the character is a quote
** STRONG QUOTE : '
** WEAK QUOTE : "
*/

bool	is_quote(int c)
{
	return ((c == STRONG_QUOTE) || (c == WEAK_QUOTE));
}
