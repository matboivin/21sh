/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:55:17 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:44:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "sh_builtins.h"

/*
** Recoded builtin echo() with option ’-n’
**
** echo [-n] [arg ...]
**     Display the ARGs, separated by a single space character and followed by a
**     newline, on the standard output.
**
** Options:
**  -n    do not append a newline
**
** returns: success
**          non-zero if a write error occurs
*/

static int	handle_newline_opt(char *arg, int *i, bool *newline)
{
	size_t	j;

	j = 0;
	if (arg[j] == '-')
		j++;
	else
		return (0);
	while (arg[j] && arg[j] == 'n')
		j++;
	if (arg[j] && arg[j] != 'n')
		return (0);
	*newline = false;
	(*i)++;
	return (1);
}

static int	dislay_args(int argc, char *arg, int *i)
{
	int		ret;

	ret = printf("%s", arg);
	(*i)++;
	if (ret != FAIL_RET)
	{
		if (*i < argc)
			ret = printf(" ");
	}
	return (ret);
}

int			echo_builtin(int argc, char **argv)
{
	int		i;
	int		ret;
	int		write_ret;
	bool	newline;

	i = FIRST_PARAM;
	ret = 1;
	write_ret = 0;
	newline = true;
	if (argc > NO_ARGS)
	{
		while (i < argc && ret)
			ret = handle_newline_opt(argv[i], &i, &newline);
		while ((i < argc) && (write_ret != FAIL_RET))
			write_ret = dislay_args(argc, argv[i], &i);
	}
	if (newline && (write_ret != FAIL_RET))
		write_ret = write(STDOUT_FILENO, "\n", 1);
	if (write_ret == FAIL_RET)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
