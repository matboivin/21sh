/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wandre_mode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:45:20 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/19 13:48:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WANDRE_MODE_H
# define WANDRE_MODE_H

# define MAX_MSG 17
# define WANDRE_PREFIX "    \033[0;31mwandre:\033[0m "
# define WAKE_WANDRE_CMD "!wandre"
# define WAKE_CMD_LEN 7
# define STOP_WANDRE_CMD "!stopit_wandre"
# define STOP_CMD_LEN 14

int		wandre_mode_is_on(char *cmd_name);
void	wake_wandre(void);
void	stop_wandre(void);
void	wandroulette(void);
void	wanderror(char *filename);

#endif
