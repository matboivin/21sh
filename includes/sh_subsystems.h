/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_subsystems.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:35:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 01:26:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SUBSYSTEMS_H
# define SH_SUBSYSTEMS_H

# include "sh_define.h"

/*
** Shell startup: loads environment, sets flags and registers signal handlers
*/

void	start_shell(char **envp);

/*
** Creates a custom shell prompt
*/

void	create_prompt(void);

/*
** Registers signal handlers
*/

void	register_signal_handlers(void);

/*
** Handles fatal error
*/

void	handle_fatal_error(int sig);

/*
** Substitutes the variable names by their values
*/

void	substitute_word(char **data);

/*
** Remove the quotes from the beginning and end of word tokens
*/

void	remove_quotes(char **data);

/*
** Checks an environment variable name format:
** underscores, digits, and ASCII letters, and that begin with a non-digit
*/

size_t	check_var_name(char *s);

#endif
