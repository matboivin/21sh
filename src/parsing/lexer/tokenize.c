/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/22 19:03:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_printf.h"
#include "sh_lexer.h"
#include "sh_utils.h"

static void	handle_text(t_lexer *lexer, char **stack)
{
	add_token_to_lexer(lexer, *stack, ft_strlen(*stack), TOKEN_WORD);
	ft_strdel(stack);
}

static int	handle_token(t_lexer *lexer, t_regex token, char **stack)
{
	if (*stack && stack)
		handle_text(lexer, stack);
	if (token.type != TOKEN_EAT)
		add_token_to_lexer(lexer, token.op, token.len, token.type);
	return (token.len);
}

static void	handle_quote(t_lexer *lexer, char **input, char quote_type)
{
	char	*stack;

	stack = NULL;
	stack = ft_strpushc(stack, input);
	while (**input && **input != quote_type)
	{
		if (**input == BACKSLASH)
		{
			stack = ft_strpushc(stack, input);
			stack = ft_strpushc(stack, input);
		}
		stack = ft_strpushc(stack, input);
	}
	if (**input == quote_type)
	{
		stack = ft_strpushc(stack, input);
		handle_text(lexer, &stack);
		return ;
	}
	ft_strdel(&stack);
	print_matching_error(quote_type);
}

/*
** This function splits the input string into tokens and handles syntax errors
*/

int			tokenize(t_lexer *lexer, char *input)
{
	t_regex	token;
	char	*stack;

	stack = NULL;
	while (input && *input)
	{
		token = search_token(input);
		if (*input == COMMENT_START)
			break ;
		if (*input == STRONG_QUOTE)
			handle_quote(lexer, &input, STRONG_QUOTE);
		else if (*input == WEAK_QUOTE)
			handle_quote(lexer, &input, WEAK_QUOTE);
		else if (token.type)
			input += handle_token(lexer, token, &stack);
		else
			stack = ft_strpushc(stack, &input);
	}
	if (stack)
		handle_text(lexer, &stack);
	return (EXIT_SUCCESS);
}
