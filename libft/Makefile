# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 23:17:16 by pabonnin          #+#    #+#              #
#    Updated: 2017/10/10 19:07:52 by pabonnin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = libft.h

ALLO = *.o
ALLC = *.c

CCO = gcc -c -Wall -Wextra -Werror
CCC = gcc -Wall -Wextra -Werror -o

all: $(NAME)

$(NAME):
	$(CCO) $(ALLC) -I./
	ar rc $(NAME) $(ALLO) 
	ranlib $(NAME)

clean:
	    /bin/rm -rf $(ALLO)

fclean: clean
	    /bin/rm -rf $(NAME)

re: fclean all
