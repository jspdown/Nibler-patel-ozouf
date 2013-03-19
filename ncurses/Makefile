NAME	=	ncurses.so

SRC_EXT	=	cpp
OBJ_EXT	=	o

INC_PATH	=	../inc/
SRC_PATH	=	./

SRC	=	$(SRC_PATH)MainWindow.cpp \
		$(SRC_PATH)NcursesLib.cpp \
		$(SRC_PATH)Window.cpp

OBJ	=	$(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

INC	=	-I $(INC_PATH) -I ./

CC	=	g++

CPPFLAGS	+=	$(INC) -g -lncurses -O3 -W -Wall -Wextra -fPIC

# Rules

all:	$(NAME)

%.$(OBJ_EXT): %.$(SRC_EXT)
	$(CC) -o $@ -c $< $(INC) $(CPPFLAGS)

$(NAME):	$(OBJ)
	$(CC) -o $@ $^ $(INC) $(CPPFLAGS) -shared -Wl,-soname,$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	clean fclean

## END
