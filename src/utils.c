/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 18:39:51 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/21 19:20:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft_str.h"
#include "shell.h"

/*
 * Returns the part of the string s after the last '/'
 */

char	*get_base_pathname(char *s)
{
	char	*head;

	head = NULL;
	if (!s)
		return (PROGRAM_NAME);
	head = ft_strrchr(s, '/');
	if (ft_strlen(s) > 1)
		head++;
	return (head);
}
