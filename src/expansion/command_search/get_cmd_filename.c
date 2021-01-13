/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 22:01:18 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:11:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_expansion.h"

/*
** This function retrieves the command filename
*/

size_t		get_cmd_filename(char *cmd_name)
{
	size_t	len;

	len = 0;
	if (contain_slash(cmd_name))
	{
		len = ft_strlen(cmd_name);
		while (cmd_name[len - 1] != '/')
			len--;
	}
	return (len);
}
