/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:27:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 19:30:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "ft_define.h"
# include "command.h"
# include "sh_env.h"
# include "lexer.h"
# include "subsystems.h"

void	print_usage(void);
void	print_error(void);
void	exit_error(void);

#endif
