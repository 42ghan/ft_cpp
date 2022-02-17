CXX			=	clang++ -std=c++98

ifdef DEBUG
	CXXFLAGS	=	-g3 -fsanitize=address
else ifdef LEAKS
	CXXFLAGS	=	-g	
else
	CXXFLAGS	=	-Wall -Werror -Wextra
endif

NAME		=	megaphone

SRCS		=	megaphone.cpp

INCLDS		=

OBJS		=	$(SRCS:%.cpp=%.o)

######################### Color #########################

GREEN="\033[32m"
L_GREEN="\033[1;32m"
YELLOW="\033[33m"
RED="\033[31m"
L_RED="\033[1;31m"
BLUE="\033[34m"
L_BLUE="\033[1;34m"
MUTED="\033[130m"
RESET="\033[0m"
BOLD="\033[1m"
L_PUPLE="\033[1;35m"
UP = "\033[A"
DOWN = "\033[B"
RIGHT = "\033[C"
LEFT = "\033[D"
CUT = "\033[K"
SAVE = "\033[s"
RESTORE = "\033[u"

########################## Rule ##########################

.PHONY		:	all
all			:	$(NAME)

$(NAME)		:	$(CXX) $(CXXFLAGS) $(OBJS) -I .