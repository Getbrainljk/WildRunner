
ifeq ($(DEBUG), yes)

CXXFLAGS	+= -g -g3 -ggdb

endif

PATH_SRCS	= ./

PATH_LIBS	= lib/

NAME		= wild_runner

CXXFLAGS	+= -Wall -Wextra -Werror -std=c++11
CXXFLAGS	+= -I./include -std=c++11
CXXFLAGS	+= -I$(PATH_LIBS)include

LDFLAGS		= -L$(PATH_LIBS)
LDFLAGS		+= -lmsdl
LDFLAGS		+= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

# Minisdl

MSDL_NAME	= $(PATH_LIBS)libmsdl.a

MSDL_SRCS	= $(PATH_LIBS)srcs/msdl_font.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/msdl_timer.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/msdl_sound.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/msdl_music.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/msdl_event.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/msdl_image.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/msdl_screen.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/msdl_surface.cpp
MSDL_SRCS	+= $(PATH_LIBS)srcs/Sprite.cpp

# Sources

SRCS		= $(PATH_SRCS)main.cpp 		\
		  src/Button.cpp		\
		  src/Environment.cpp 		\
		  src/Images.cpp 		\
		  src/Character.cpp		\
		  src/Map.cpp			\
		  src/SoundOfTheWild.cpp

OBJS		= $(SRCS:.cpp=.o)
MSDL_OBJS	= $(MSDL_SRCS:.cpp=.o)

AR		= ar rc

RAN		= ranlib

RM		= rm -f

all: $(MSDL_NAME) $(NAME)

$(MSDL_NAME): $(MSDL_OBJS)
	$(AR) $(MSDL_NAME) $(MSDL_OBJS)
	$(RAN) $(MSDL_NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(MSDL_OBJS)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(MSDL_NAME)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
