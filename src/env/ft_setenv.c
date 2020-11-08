/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:14:01 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 20:36:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"

/*
** This function adds a new definition to the environment
** If the new entry already exists and replace is false, nothing happens.
** Otherwise, the entry is replaced by the new one.
**
** to_set: Name of the variable
** new_value: Value of the variable
** replace: true or false
**
** returns: 0 on success
**          -1 on error
*/

int		ft_setenv(char *to_set, char *new_value, bool replace)
{
	if (!to_set || !new_value)
		return (FAIL_RET);
	(void)replace;
	return (0);
}
