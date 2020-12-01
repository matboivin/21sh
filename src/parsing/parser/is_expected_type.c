/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expected_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:00:11 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/01 20:00:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sh_parser.h"

bool	is_expected_type(t_tok_type current, t_tok_type expected)
{
	return (current == expected);
}
