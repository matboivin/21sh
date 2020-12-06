/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_subsystems.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:35:27 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/06 18:33:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_SUBSYSTEMS_H
# define SH_SUBSYSTEMS_H

# include "sh_define.h"

/*
** Shell startup: loads environment, sets flags and registers signal handlers
*/

void	start_shell(char **envp, char *argv0);

/*
** Creates shell prompt
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

#endif
