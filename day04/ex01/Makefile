NAME	=	singleton

CXX	=	c++
CXXFLAGS	=	-Wall -Werror -Wextra

SR	=	src/

SRCS	=	main.cpp \
			Persons.cpp \
			Rooms.cpp \
			Staff.cpp

OBJS	=	$(SRCS:.cpp=.o)

RED = \033[0;31m
WHITE = \033[0;32m
BLUE = \033[0;34m
WHITE = \033[1;37m
NO_COLOR = \033[0m

all	: $(NAME)

$(NAME) : $(OBJS)
	@ $(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(RED)$(NAME)$(NO_COLOR)$(WHITE) has been created !$(NO_COLOR)"

clean:
	@rm -rf $(OBJS)
	@echo "$(RED)$(NAME)$(RED) objects have been removed !"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME)$(WHITE) has been removed !"

.c.o:
	@ ${CXX} ${CXXFLAGS} -c $< -o ${<:.c=.o}

re:	fclean all

.PHONY : all clean fclean re