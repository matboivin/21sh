/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expected_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:00:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 17:31:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sh_parser.h"

/*
** This function checks whether the token type is the one expected
*/

bool	is_expected_type(t_tok_type current, t_tok_type expected)
{
	return (current == expected);
}
