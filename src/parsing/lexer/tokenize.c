/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/22 17:29:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "libft_printf.h"
#include "sh_lexer.h"
#include "sh_utils.h"

/*
** This function raises a syntax error
*/

static int	raise_syntax_error(const char *token)
{
	g_status = INCORRECT_USAGE;
	print_syntax_error(token);
	return (FAIL_RET);
}

static int	raise_matching_error(char c)
{
	print_match_error(c);
	return (FAIL_RET);
}

static void	handle_text(t_lexer *lexer, char **s)
{
	add_token_to_lexer(lexer, *s, ft_strlen(*s), TOKEN_WORD);
	ft_strdel(s);
}

// TODO: ' and !

static int	handle_strong_quotes(t_lexer *lexer, char **input)
{
	char	*stack;

	stack = NULL;
	stack = ft_strpushc(stack, input);
	while (**input && **input != STRONG_QUOTE)
		stack = ft_strpushc(stack, input);
	if (**input == STRONG_QUOTE)
	{
		stack = ft_strpushc(stack, input);
		handle_text(lexer, &stack);
		return (0);
	}
	ft_strdel(&stack);
	return (raise_matching_error(STRONG_QUOTE));
}

// TODO: Handle var expansion and cmd subtition

static int	handle_weak_quotes(t_lexer *lexer, char **input)
{
	char	*stack;

	stack = NULL;
	stack = ft_strpushc(stack, input);
	while (**input && **input != WEAK_QUOTE)
		stack = ft_strpushc(stack, input);
	if (**input == WEAK_QUOTE)
	{
		stack = ft_strpushc(stack, input);
		handle_text(lexer, &stack);
		return (0);
	}
	ft_strdel(&stack);
	return (raise_matching_error(WEAK_QUOTE));
}

static void	handle_quotes(t_lexer *lexer, char **input)
{
	if (**input == STRONG_QUOTE)
		handle_strong_quotes(lexer, input);
	else
		handle_weak_quotes(lexer, input); // tmp
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
		if (!stack && token.type == TOKEN_HASH)
			break ;
		if (token.type == TOKEN_DSEMI)
			return (raise_syntax_error(token.op));
		if (token.type == TOKEN_BACKSLASH)
		{
			input++;
			stack = ft_strpushc(stack, &input);
		}
		else if ((*input == STRONG_QUOTE) || (*input == WEAK_QUOTE))
			handle_quotes(lexer, &input);
		else if (token.type && token.type != TOKEN_HASH)
		{
			if (stack)
				handle_text(lexer, &stack);
			if (token.type != TOKEN_EAT)
				add_token_to_lexer(lexer, token.op, token.len, token.type);
			input += token.len;
		}
		else
			stack = ft_strpushc(stack, &input);
	}
	if (stack)
		handle_text(lexer, &stack);
	return (EXIT_SUCCESS);
}
