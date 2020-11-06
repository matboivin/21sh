/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:43:59 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 19:53:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# include <stdbool.h>

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

extern t_env		*g_env;

void				fill_env(char **environ);
void				init_env(char **environ);
int					ft_setenv(char *key, char *value, bool replace);
int					ft_unsetenv(const char *key);
int					ft_clearenv(void);
char				*ft_getenv(const char *key);

#endif
