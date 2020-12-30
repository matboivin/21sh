BIN_NAME := minishell

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

# ********************************* INCLUDES ********************************* #

INC_FILES	=	minishell.h					\
				sh_ast.h					\
				sh_builtins.h				\
				sh_command.h				\
				sh_ctrl.h					\
				sh_define.h					\
				sh_env.h					\
				sh_execution.h				\
				sh_input_processing.h		\
				sh_lexer.h					\
				sh_parser.h					\
				sh_subsystems.h				\
				sh_utils.h

# ********************************* C FILES ********************************** #

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

# INPUT PROCESSING #

SRC_FILES	+=	get_command.c				\
				process_input.c				\
				shell_loop.c

# LEXER #

SRC_FILES	+=	add_token_to_lexer.c		\
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

# EXECUTION #

SRC_FILES	+=	add_simple_cmd.c			\
				build_cmd_table.c			\
				command.c					\
				contain_slash.c				\
				create_pipe.c				\
				exec_pipe_seq.c				\
				execute.c					\
				is_builtin.c				\
				is_open_file.c				\
				get_cmd_arg_count.c			\
				get_cmd_args.c				\
				get_cmd_filename.c			\
				get_files.c					\
				redirect_stream.c			\
				search_builtin.c			\
				search_command.c			\
				simple_command.c			\
				spawn_process.c				\
				traverse_tree.c

# SUBSYSTEMS #

SRC_FILES	+=	create_prompt.c				\
				get_var_len.c				\
				handle_fatal_error.c		\
				register_signal_handlers.c	\
				remove_quotes.c				\
				sh_ctrl.c					\
				start_shell.c				\
				substitute_word.c

# ENV HANDLING #

SRC_FILES	+=	dup_environment.c			\
				ft_clearenv.c				\
				ft_findenv.c				\
				ft_getenv.c					\
				ft_printenv.c				\
				ft_putenv.c					\
				ft_setenv.c					\
				ft_unsetenv.c				\
				is_valid_identifier.c		\
				load_environment.c			\
				set_working_dir.c

# UTILS #

SRC_FILES	+=	builtin_error.c				\
				is_directory.c				\
				print_error.c				\
				print_usage.c				\
				exit_shell.c				\
				free_all.c

# ********************************* OBJECTS ********************************** #

OBJ_FILES		=	$(SRC_FILES:%.c=%.o)

# *********************************** LIBS *********************************** #

LIBS		=	ft

# ****************************** DIRS AND PATHS ****************************** #

LIB_DIR		=	libft

INC_DIR		=	includes
SRC_DIR		=	src
OBJ_DIR		=	obj

SUB_DIRS	=	builtins					\
				execution					\
				execution/command_search	\
				execution/command_table		\
				input_processing			\
				parsing/lexer				\
				parsing/parser				\
				parsing/tree				\
				subsystems					\
				subsystems/env_utils		\
				subsystems/signals			\
				subsystems/substitution		\
				utils

SRC_SUBDIRS	=	$(addprefix $(SRC_DIR)/, $(SUB_DIRS))

INC			=	$(addprefix $(INC_DIR)/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

INC_PATHS	=	$(INC_DIR) $(addsuffix /$(INC_DIR), $(LIB_DIR))

VPATH		=	$(SRC_DIR) $(SRC_SUBDIRS)

# *************************** COMPILING AND FLAGS **************************** #

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(foreach path, $(INC_PATHS), -I$(path))
LDFLAGS		=	-L$(LIB_DIR)
LDLIBS		=	$(foreach lib, $(LIBS), -l$(lib))

DEBUG_CFLAGS = -D DEBUG

# ********************************** RULES *********************************** #

all: $(BIN_NAME)

# INSTALL #

install :
	@make -C $(LIB_DIR)

re-install :
	@make -C $(LIB_DIR) fclean
	@make install

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.c $(INC)
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<

# LINKING #

$(BIN_NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nOK\t\t$@ is ready"

# DEBUG #

show:
	@echo "VPATH: $(VPATH)"

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: re
	@echo "DEBUG\t\tDebug build done"

check_leaks: $(BIN_NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./minishell

show_tree:
	@dot -Tsvg ast.dot -o ast.svg
	@xdg-open ast.svg

# CLEAN #

clean:
	@make -C $(LIB_DIR) clean
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) -f $(BIN_NAME)
	@echo "Removed\t\t$(BIN_NAME)"

re: fclean all

.PHONY: all install re-install show debug show_tree check_leaks clean fclean re
