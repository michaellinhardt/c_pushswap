# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/13 20:28:51 by mlinhard          #+#    #+#              #
#    Updated: 2016/03/29 04:54:56 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror -g

SRCS	=	main.c \

HDIR 	=	./includes/
LDIR 	= 	./libft/
SRCSDIR = 	./srcs/
SRC 	=	$(addprefix $(SRCSDIR), $(SRCS))

RE			= \033[0;31m
GR			= \033[0;32m
YE			= \033[0;33m
BL			= \033[0;34m
WH			= \033[0;38m
OK			= $(WH)* [ $(GR)OK $(WH)]
KO			= $(WH)* [ $(RE)KO $(WH)]
W8			= $(WH)* [ $(BL)W8 $(WH)]

all: $(NAME)

$(NAME):
	@echo "$(W8) $(YE)make -C $(LDIR)$(WH)"
	@make -C $(LDIR)
	@echo "$(W8) $(YE)$(CC) $(FLAGS) (SRC) -o $(NAME) -I$(HDIR) -L$(LDIR) -lft$(WH)"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I$(HDIR) -I./ -L$(LDIR) -lft
	@echo "$(OK) $(GR)Done!$(WH)"

clean:
#@echo "$(W8) $(YE)make clean -C $(LDIR)$(WH)"
#@make clean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf $(NAME)$(WH)"
	@/bin/rm -rf $(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

fclean: clean
#@echo "$(W8) $(YE)make fclean -C $(LDIR)$(WH)"
#@make fclean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf ./*.dSYM$(WH)"
	@/bin/rm -rf ./*.dSYM
	@echo "$(OK) $(GR)Done!$(WH)"

re: fclean all

test: re
	@echo "$(W8) $(YE)time ./$(NAME)"
	@time ./$(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

leaks: re -leaks
-leaks:
	@echo "$(W8) $(YE)valgrind --leak-check=yes --track-origins=yes ./$(NAME)$(WH)"
	@-valgrind --leak-check=yes --track-origins=yes ./$(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

.PHONY: all clean fclean re test leaks
