 NAME	=	a.out
SRC		=	main.cpp
OBJ		=	main.o

all		:	$(NAME)
$(NAME) : $(SRC)
			clang++  -Wall -Wextra -Werror \
			-std=c++98 -I includes $(SRC) -o $(NAME) 
clean	:
		rm -f $(NAME)
fclean	: clean	
re		: fclean
		make all