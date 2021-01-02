/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 01:11:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/02 01:52:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_subsystems.h"

void	remove_backslash(char **result, char *tok_word, size_t *i)
{
	(*i)++;
	*result = ft_append_char(*result, tok_word + *i, true);
}
