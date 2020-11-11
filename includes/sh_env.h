/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 15:18:16 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# include <stdbool.h>
# include "sh_define.h"

/*
** Shell startup: loads environment and sets flags
*/

void	start_shell(char **envp);

/*
** Retrieves the environment from envp
*/

void	load_environment(char **envp);

/*
** Duplicates the environment
*/

char	**dup_env(size_t count);

/*
** Searches for the environment variable which name is key
*/

int		find_env(char *key);

/*
** Returns a string that is the value of the environment variable key
*/

char	*ft_getenv(char *key);

/*
** Appends a new definition to the environment
*/

int		ft_putenv(char *s);

/*
** Adds or replaces a new definition to the environment
*/

int		ft_setenv(char *key, char *new_value, bool replace);

/*
** Removes an entry from the environment
*/

int		ft_unsetenv(char *key);

/*
** Removes all entries from the environment
*/

void	ft_clearenv(void);

/*
** Prints name and value pairs for all environment variables
*/

void	ft_printenv(void);

#endif
