# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:12:33 by pdolinar          #+#    #+#              #
#    Updated: 2022/09/21 19:56:11 by pdolinar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell
HEADER		=	$(INC)/minishell.h
HEADER_L	=	$(LIBFT_DIR)/$(INC)/libft.h
INC			=	include
INC_L		=	$(LIBFT_DIR)/include
READLINE   	=	-lreadline
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf

OS:= $(shell uname -s)
ifeq ($(OS), Darwin)
	READLINE_LIB	=	-I $(HOME)/goinfre/.brew/opt/readline/include/ $(READLINE)#\
						#-L$(HOME)/goinfre/.brew/opt/readline/lib/ $(READLINE)
endif

ifeq ($(OS), Linux)
	READLINE_LIB	=	 -L/usr/local/opt/readline/lib $(READLINE)
endif

CLEAR = \033[0m
PR = \033[1;35m
GR = \033[1;32m

SRC_DIR		=	src/
OBJ_DIR		=	build/

SRC			=	main.c \
				#parsing.c \
				utils.c \
				utils_2.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRC:.c=.o)))

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(READLINE_LIB)
	@echo "$(GR)>> compiling ...									   \n \
      _______ _____ __   _ _____ _______ _     _ _______               \n \
      |  |  |   |   | \  |   |   |______ |_____| |______ |      |      \n \
      |  |  | __|__ |  \_| __|__ ______| |     | |______ |_____ |_____ \n \
                                                             		$(REV)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER) $(HEADER_L)
	@$(CC) $(CFLAGS) -I $(INC) -I $(INC_L) -c $< -o $@

$(LIBFT):
	@$(MAKE) all -s -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	$(MAKE) fclean -s -C $(LIBFT_DIR)
	@echo "$(PR)All object files deleted$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(PR)$(NAME) deleted$(CLEAR)"

norm:
	norminette $(SRC_DIR) $(INC)

re:	fclean all

.PHONY: all clean fclean re norm
