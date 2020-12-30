/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 21:29:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 21:35:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "sh_utils.h"

/*
** This function checks whether a file is a directory
** st_mode: File type and mode
*/

int				is_directory(char *pathname)
{
	struct stat	statbuf;
	int			ret;

	ret = stat(pathname, &statbuf);
	if (ret != FAIL_RET)
		return (S_ISDIR(statbuf.st_mode));
	return (ret);
}
