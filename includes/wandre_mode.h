/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wandre_mode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:45:20 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/15 22:52:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WANDRE_MODE_H
# define WANDRE_MODE_H

# define MAX_MSG 16
# define WANDRE_PREFIX "    \033[0;31mwandre:\033[0m "

void	wake_wandre(void);
void	wandroulette(void);
int		wanderror(char *filename);

#endif
