/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:04:09 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 20:35:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"

/*
** This function removes an entry from the environment
**
** to_unset: Name of the variable to remove
**
** returns: 0 on success
**          -1 on error
*/

int				ft_unsetenv(char *to_unset)
{
	(void)to_unset;
	return (0);
}
