/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/21 19:36:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define PROGRAM_NAME "42sh"

extern char	**g_shell_environment;

typedef struct	s_shell
{
	int			interactive_shell;
	int			login_shell;
	char		*shell_name;
}				t_shell;

void	put_shell_usage(char *argv0);

t_shell	*init_shell(void);
void	exit_shell(t_shell **to_free);

void	set_shell(t_shell *shell, int argc, char **argv, char **envp);

#endif
