# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 17:23:28 by pdiedra           #+#    #+#              #
#    Updated: 2019/07/18 20:12:56 by vsanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIB 		= libft/libft.a

NAME_PS 		= push_swap
NAME_CHECK 		= checker

INC_DIR 		= ./includes/
INC_LIB_FT 		= ./libft/includes/
SRC_DIR 		= ./src/
OBJ_DIR 		= ./obj/

SRC_NAME_PS		= commands_utils.c sort.c stack.c stack_push.c valid.c \
					commands.c sort_utils.c stack_pop.c utils.c push_swap.c

SRC_NAME_CHECK	= commands_utils.c sort.c stack.c stack_push.c valid.c \
					commands.c sort_utils.c stack_pop.c utils.c checker.c

SRC_PS			= $(addprefix $(SRC_PATH), $(SRC_NAME_PS))
SRC_CHECK		= $(addprefix $(SRC_PATH), $(SRC_NAME_CHECK))
OBJ_PS			= $(addprefix $(OBJ_DIR), $(SRC_NAME_PS:.c=.o))
OBJ_CHECK		= $(addprefix $(OBJ_DIR), $(SRC_NAME_CHECK:.c=.o))

CC				= gcc
FLAGS			= -Wall -Wextra -Werror
GCC_LIBFT 		= -L ./libft -l ft

all: $(NAME_PS) $(NAME_CHECK)

$(NAME_PS): $(OBJ_DIR) $(OBJ_PS) $(NAME_LIB)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_PS) $(FLAGS) -o $(NAME_PS)

$(NAME_CHECK): $(OBJ_DIR) $(OBJ_CHECK) $(NAME_LIB)
	$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_CHECK) $(FLAGS) -o $(NAME_CHECK)

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c -I $(INC_DIR) -I $(INC_LIB_FT) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME_PS) $(NAME_CHECK)
	@make fclean -C libft/

re: fclean all