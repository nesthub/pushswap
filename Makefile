# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/13 20:28:51 by mlinhard          #+#    #+#              #
#    Updated: 2016/04/26 20:49:39 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap
CC		=	gcc
CFLAGS1	=	-g
CFLAGS2	=	-Wall -Wextra -Werror
CFLAGS	=	$(CFLAGS2)

SRCS	=	ft_pushswap.c \
			ft_pushswap_parse.c \
			ft_pushswap_solver.c \
			ft_pushswap_options.c \
			ft_pushswap_bubble3.c \
			ft_pushswap_move1.c \
			ft_pushswap_stupid.c \
			ft_pushswap_stupid_pushb.c \
			ft_pushswap_move2.c \
			ft_pushswap_bubble1.c \
			ft_pushswap_move3.c \
			ft_pushswap_bubble2.c \
			ft_pushswap_move4.c \
			ft_pushswap_stupid2.c \
			ft_pushswap_move5.c \
			ft_pushswap_verbose.c \
			ft_pushswap_verbose_init.c \
			ft_pushswap_free.c

INCLUDES 	= -I./includes/ -I./libft/includes/
LDIR 		= ./libft/
SRCSDIR 	= ./srcs/
SRC 		= $(addprefix $(SRCSDIR), $(SRCS))

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
	@echo "$(W8) $(YE)make clean -C $(LDIR)$(WH)"
	@make clean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf $(NAME)$(WH)"
	@/bin/rm -rf $(NAME)
	@echo "$(OK) $(GR)Done!$(WH)"

fclean: clean
	@echo "$(W8) $(YE)make fclean -C $(LDIR)$(WH)"
	@make fclean -C $(LDIR)
	@echo "$(W8) $(YE)/bin/rm -rf ./*.dSYM$(WH)"
	@/bin/rm -rf ./*.dSYM
	@echo "$(OK) $(GR)Done!$(WH)"

re: fclean all

.PHONY: all clean fclean re
