SRC_FILES	=	main.c

# BUILT-IN FUNCTIONS #

SRC_FILES	+=	cd_builtin.c				\
				display_export.c			\
				echo_builtin.c				\
				env_builtin.c				\
				exit_builtin.c				\
				export_builtin.c			\
				pwd_builtin.c				\
				unset_builtin.c

# EXECUTION #

SRC_FILES	+=	dup_streams.c				\
				exec_pipe_seq.c				\
				exec_simple_cmd.c			\
				execute.c					\
				invoke_builtin.c			\
				is_builtin.c				\
				handle_redirection.c		\
				redirect_stream.c			\
				restore_default_streams.c	\
				spawn_process.c

# EXPANSION#

SRC_FILES	+=	add_simple_cmd.c			\
				build_cmd_table.c			\
				command.c					\
				contain_slash.c				\
				expand_word.c				\
				is_open_file.c				\
				get_cmd_arg_count.c			\
				get_cmd_args.c				\
				get_cmd_filename.c			\
				get_files.c					\
				search_builtin.c			\
				search_command.c			\
				simple_command.c			\
				traverse_tree.c

# INPUT PROCESSING #

SRC_FILES	+=	get_command.c				\
				process_input.c				\
				wait_for_input.c

# LEXER #

SRC_FILES	+=	add_token_to_lexer.c		\
				add_word_to_lexer.c			\
				eat.c						\
				escape_char.c				\
				get_token.c					\
				get_next_token.c			\
				handle_quotes.c				\
				handle_text.c				\
				handle_token.c				\
				increase_lexer.c			\
				lexer.c						\
				lexer_is_full.c				\
				push_char.c					\
				token.c						\
				tokenize.c

# PARSER #

SRC_FILES	+=	parse.c						\
				parse_cmd_suffix.c			\
				parse_command.c				\
				parse_io_file.c				\
				parse_pipe_sequence.c		\
				parse_simple_cmd.c			\
				parse_word.c

# AST #

SRC_FILES	+=	ast.c						\
				append_node.c				\
				print_ast.c					\
				save_ast_dot.c				\
				save_ast_svg.c				\
				write_ast_dot.c

# SUBSYSTEMS #

SRC_FILES	+=	create_prompt.c				\
				handle_fatal_error.c		\
				is_quote.c					\
				register_signal_handlers.c	\
				remove_backslash.c			\
				remove_quotes.c				\
				sh_ctrl.c					\
				start_shell.c				\
				substitute_var.c

# ENV HANDLING #

SRC_FILES	+=	dup_environment.c			\
				ft_clearenv.c				\
				ft_findenv.c				\
				ft_getenv.c					\
				ft_printenv.c				\
				ft_putenv.c					\
				ft_setenv.c					\
				ft_unsetenv.c				\
				get_env_len.c				\
				is_valid_identifier.c		\
				load_environment.c			\
				set_working_dir.c

# UTILS #

SRC_FILES	+=	builtin_error.c				\
				handle_error.c				\
				is_directory.c				\
				print_error.c				\
				print_usage.c				\
				exit_shell.c				\
				free_all.c

# FEATURE #

SRC_FILES	+=	wandre_mode.c
