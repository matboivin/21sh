/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:33:44 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:19:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# include <stdbool.h>
# include "sh_define.h"

/*
** Retrieves the environment from envp
*/

void	load_environment(char **envp);

/*
** Duplicates the environment
*/

char	**dup_environment(size_t count, bool replace);

/*
** Searches for the environment variable which name is key
*/

int		ft_findenv(char *key);

/*
** Calculates the length of an environment variable
*/

int		get_env_len(char *key);

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

int		ft_printenv(void);

/*
** Sets the current working directory value
*/

int		set_working_dir(void);

/*
** Checks whether an environment variable name begins by a letter or by
** an underscore, and not by an equal sign
*/

int		is_valid_identifier(char *s);

#endif
