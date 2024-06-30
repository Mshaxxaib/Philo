# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mshazaib <mshazaib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 19:15:19 by mshazaib          #+#    #+#              #
#    Updated: 2024/06/30 19:40:01 by mshazaib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo
SRC_DIR 	= src
OBJ_DIR 	= obj
INC_DIR 	= -Iincludes
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
PHILO_FLAGS = -g -pthread
RM 			= rm - rf

SRC 		= philo.c\
			philo_check_pulse.c\
			philo_free\
			philo_init\
			philo_print\
			philo_solo\
			philo_spawn\
			philo_utils\

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%c=%o))

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "Compiling:"
	$(CC) $(CFLAGS) $(PHILO_FLAGS) $(INC_DIR) -c $< -o $@

$(NAME) : $(OBJ)
	@printf "SIM READY!\n"
	@$(CC) $(CFLAGS) $(PHILO_FLAGS) $(OBJ) -o $(NAME)

clean:
	@printf "CLEANING OBJ JUNK\n"
	@$(RM) $(OBJ_DIR)
fclean: clean
	@printf "CLEANING PROGRAM ITSELF\n"
re: fclean all

.PHONY = all clean fclean re