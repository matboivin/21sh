BIN_NAME := ft_sh

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

# ********************************* INCLUDES ********************************* #

INC_FILES	=	ft_sh.h					\
				sh_builtin.h			\
				sh_ctrl.h				\
				sh_define.h				\
				sh_env.h				\
				sh_input_processing.h	\
				sh_lexer.h				\
				sh_parser.h				\
				sh_subsystems.h			\
				sh_utils.h

# ********************************* C FILES ********************************** #

SRC_FILES	=	main.c					\
				sh_ctrl.c				\
				print_usage.c			\
				exit_error.c			\
				exit_ft_sh.c			\
				free_all.c

# BUILT-IN FUNCTIONS #

SRC_FILES	+=	ft_env.c

# INPUT PROCESSING #

SRC_FILES	+=	shell_loop.c

# LEXER #

SRC_FILES	+=	fill_lexer.c			\
				lexer.c					\
				tokens.c

# SIGNAL HANDLING #

SRC_FILES	+=	handle_fatal_error.c		\
				register_signal_handlers.c

# SUBSYSTEMS #

SRC_FILES	+=	ft_clearenv.c		\
				ft_findenv.c		\
				ft_getenv.c			\
				ft_printenv.c		\
				ft_putenv.c			\
				ft_setenv.c			\
				ft_unsetenv.c		\
				dup_environment.c	\
				load_environment.c	\
				start_shell.c

# ********************************* OBJECTS ********************************** #

OBJ_FILES		=	$(SRC_FILES:%.c=%.o)

# *********************************** LIBS *********************************** #

LIBS		=	ft

# ****************************** DIRS AND PATHS ****************************** #

LIB_DIR		=	libft

INC_DIR		=	includes
SRC_DIR		=	src
OBJ_DIR		=	obj

SUB_DIRS	=	builtin				\
				input_processing	\
				parsing				\
				subsystems			\
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

DEBUG_CFLAGS = -g -D DEBUG

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

# Debug build for gdb debugging #

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: re
	@echo "DEBUG\t\tDebug build done"

check_leaks: $(BIN_NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_sh

# CLEAN #

clean:
	@make -C $(LIB_DIR) clean
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) -f $(BIN_NAME)
	@echo "Removed\t\t$(BIN_NAME)"

re: fclean all

.PHONY: all install re-install show debug check_leaks clean fclean re
