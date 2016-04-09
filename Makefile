# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/13 20:28:51 by mlinhard          #+#    #+#              #
#    Updated: 2016/04/09 06:39:46 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		=	gcc
CFLAGS1	=	-g
CFLAGS2	=	-Wall -Wextra -Werror -g
CFLAGS	=	$(CFLAGS1)

SRCS	=	ft_pushswap.c \
			ft_pushswap_parse.c \
			ft_pushswap_handler.c \
			ft_pushswap_move.c \
			ft_pushswap_print.c \
			ft_pushswap_presolve.c \
			ft_pushswap_verbose.c \
			ft_pushswap_free.c

INCLUDES 	= -I./includes/ -I./libft/includes/
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
	@echo "$(W8) $(YE)$(CC) $(CFLAGS) (SRC) -o $(NAME) $(INCLUDES) -L$(LDIR) -lft$(WH)"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME) $(INCLUDES) -L$(LDIR) -lft
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

test: all -test fclean
-test:
	@echo "$(W8) $(YE)time ./$(NAME)$(WH)"
	@time ./$(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

leaks: all -leaks fclean

-leaks:
	@echo "$(W8) $(YE)valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)$(WH)"
	@-valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

.PHONY: all clean fclean re test leaks
