/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contain_slash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 21:44:18 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/21 23:17:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_execution.h"

/*
** This function checks whether the command path contains any slashes
*/

bool	contain_slash(char *cmd_path)
{
	return (ft_strchr(cmd_path, '/') != NULL);
}
