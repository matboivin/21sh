/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:30:22 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:46:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_define.h"
#include "ft_env.h"

char		*get_path_value(char **environ)
{
	char	*path_value;

	path_value = ft_getenv(environ, "PATH");
	if (!path_value)
		path_value = DEFAULT_PATH;
	return (path_value);
}
