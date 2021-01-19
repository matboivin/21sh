/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_subsystems.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:35:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/19 13:07:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SUBSYSTEMS_H
# define SH_SUBSYSTEMS_H

# include <stdbool.h>
# include "sh_define.h"

/*
** Shell startup: loads environment, sets flags and registers signal handlers
*/

void	start_shell(char **envp);

/*
** Displays a prompt and get user's input
*/

char	*sh_readline(const char *prompt);

/*
** Creates a custom shell prompt
*/

char	*create_prompt(void);

/*
** Registers signal handlers
*/

void	register_signal_handlers(void);

/*
** Handles fatal error
*/

void	handle_fatal_error(int sig);

/*
** Quotes removal, backslash escaping and environment variables substitution
*/

void	substitute_var(char **result, char *tok_word, size_t *i);
void	remove_quotes(char **result, char *tok_word, size_t *i);
void	remove_backslash(char **result, char *tok_word, size_t *i, bool check_special);

/*
** Checks whether the character is a quote
*/

bool	is_quote(int c);

#endif
