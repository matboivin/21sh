/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_subsystems.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:35:27 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 23:59:27 by mboivin          ###   ########.fr       */
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
** Substitutes the variable names by their values
*/

void	expand_word(char **tok_word);
void	substitute_var(char **result, char *tok_word, size_t *i);

/*
** Remove the quotes from the beginning and end of word tokens
*/

void	remove_quotes(char **data);

#endif
