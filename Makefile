# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 14:38:01 by arobu             #+#    #+#              #
#    Updated: 2023/01/05 03:31:13 by arobu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME			= push_swap
CHECKER			= checker
INCLUDE			= -I include/
SRC_DIR			= ./src
OBJ_DIR			= ./obj
LIBFT_FOLDER	= ./libft
LIBFT_LIB		= ./libft/libft.a
MAIN_FILE		= main.c
MAIN_CHECKER	= checker_main.c
# Compiler

CC			= cc
CFLAGS		= #-fsanitize=address -g3 #-Wall -Werror -Wextra 
LDLFLAGS	= -L./libft/ -lft

#Archive and Remove

RM			= rm -f
AR			= ar rcs

# Colors

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;32m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources

PUSH_SWAP_SRCS	=	$(wildcard $(SRC_DIR)/*.c)
PUSH_SWAP_OBJS	= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(PUSH_SWAP_SRCS))

all: libft $(NAME)

$(NAME): $(PUSH_SWAP_OBJS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(PUSH_SWAP_OBJS) $(MAIN_FILE) $(LDLFLAGS)
	@echo "$(CYAN)Push Swap built successfully.$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ echo "$(MAGENTA)Compiling file $<.$(DEF_COLOR)"
	@ $(CC) $(CFLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
			@make all -C $(LIBFT_FOLDER)

 clean:
			@$(RM) -rdf $(OBJ_DIR)
			@make clean -C $(LIBFT_FOLDER)
			@echo "$(CYAN)Libraries successfully cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(CHECKER)
			@echo "$(CYAN)Executables successfully cleaned!$(DEF_COLOR)"
			@$(RM) -f $(LIBFT_LIB)


re:			fclean all

bonus:	$(CHECKER) 	

$(CHECKER): $(PUSH_SWAP_OBJS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(PUSH_SWAP_OBJS) $(MAIN_CHECKER) $(LDLFLAGS)
	@echo "$(CYAN)Push Swap built successfully.$(DEF_COLOR)"

norm:
			@norminette $(SRC_DIR) $(INCLUDE) | grep -v OK
		
.PHONY:		all libft clean fclean re norm
