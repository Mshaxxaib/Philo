# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalbrei <amalbrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 15:27:54 by amalbrei          #+#    #+#              #
#    Updated: 2022/11/25 15:22:31 by amalbrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


DEFAULT	=	\033[0m
RED		=	\033[1;31m
GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
PURPLE	=	\033[0;35m
CYAN	=	\033[1;36m

NAME	=	philo
SRC_DIR	=	Source_Files
OBJ_DIR	=	Object_Files
INC_DIR =	-IIncludes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
PHILO_FLAGS = -g -pthread
RM		=	rm	-rf

SRC 	=	philo.c\
			philo_init.c\
			philo_free.c\
			philo_summon.c\
			philo_life.c\
			philo_print.c\
			philo_check_pulse.c\
			philo_solo.c\
			philo_very_curious.c

OBJ	= 	$(addprefix $(OBJ_DIR)/, $(SRC:%c=%o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf "\033[A\033[2K\r$(GREEN)Compiling:"
	$(CC) $(CFLAGS) $(PHILO_FLAGS) $(INC_DIR) -c $< -o $@
	@printf "🌚🧑‍🍳🧑‍🍳🧑‍🍳🧑‍🍳🧑‍🍳🧑‍🍳🧑‍🍳🧑‍🍳💆‍♂️💆‍♂️💆‍♀️💆‍♀️💆‍♂️💆‍♂️💆‍♀️💆‍♀️📜📜📜📜📜📜📜📜🌝"

$(NAME): $(OBJ)
	@printf "$(CYAN)\n==========================\n"
	@printf "$(CYAN) SIMULATION READY\n"
	@printf "$(CYAN)==========================\n"
	@$(CC) $(CFLAGS) $(PHILO_FLAGS) $(OBJ) -o $(NAME)

clean:
	@printf "$(RED)CLEANING PHILO.O FILES\n"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@printf "$(RED)CLEANING PHILOSOPHERS PROGRAM\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re