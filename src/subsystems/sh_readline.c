/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:04:23 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/19 13:09:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_define.h"
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_subsystems.h"

/*
** This function checks for a newline character in the content pointed to by
** line. If a newline is found, line is updated and true is returned.
**
** line: The value of what has been read
**
** returns: true if a newline character has been found
**          false otherwise
*/

static bool	ft_is_line(char **line)
{
	char	*newline;
	char	*sub_string;
	size_t	line_end;

	newline = NULL;
	newline = ft_strchr(*line, NEWLINE);
	if (newline != NULL)
	{
		line_end = newline - *line;
		sub_string = ft_substr(*line, 0, line_end);
		*line = ft_strreplace(*line, sub_string);
		ft_strdel(&sub_string);
		return (true);
	}
	return (false);
}

/*
** Adapted readline function: displays the prompt on stderr and read the input
** one char by one char
*/

char		*sh_readline(const char *prompt)
{
	int		bytes_read;
	char	buffer[INPUT_BUFF_SIZE + 1];
	char	*line;

	line = NULL;
	if (prompt)
		ft_dprintf(STDERR_FILENO, "%s", prompt);
	bytes_read = read(STDIN_FILENO, buffer, INPUT_BUFF_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		line = ft_strjoindelone(line, buffer);
		if (!line)
			return (NULL);
		if (ft_is_line(&line))
			return (line);
		bytes_read = read(STDIN_FILENO, buffer, INPUT_BUFF_SIZE);
	}
	return (line);
}
