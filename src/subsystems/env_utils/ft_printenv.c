/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:44:39 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 15:59:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_printf.h"
#include "sh_env.h"

/*
** This function prints name and value pairs for all environment variables
*/

int			ft_printenv(void)
{
	size_t	i;
	int		ret_val;

	if (!g_env)
		return (EXIT_FAILURE);
	i = 0;
	ret_val = 0;
	while (g_env[i] && (ret_val != FAIL_RET))
		ret_val = ft_printf("%s\n", g_env[i++]);
	if (ret_val == FAIL_RET)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
