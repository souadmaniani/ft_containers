NAME	=	a.out
SRC		=	main.cpp 
OBJ		=	main.o

all		:	$(NAME)
$(NAME) : $(SRC)
			clang++  -Wall -Wextra -Werror \
			-std=c++98 -I includes $(SRC) -o $(NAME) 
clean	:
		rm -f $(NAME)
		rm -rf a.out.dSYM
fclean	: clean	
re		: fclean
		make all