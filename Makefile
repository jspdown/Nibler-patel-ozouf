NAME	=	nibler

SRC_EXT	=	cpp
OBJ_EXT	=	o


INC_PATH	=	./inc/
SRC_PATH	=	./src/
EVENT		=	$(SRC_PATH)Event/
EVENT_HANDLER	=	$(EVENT)Handler/
EVENT_ENTITY	=	$(EVENT)Entity/
LIBRARY		=	$(SRC_PATH)Library/

SRC	=	$(EVENT_HANDLER)HandleEvent.cpp \
		$(EVENT_HANDLER)Listener.cpp \
		$(EVENT_HANDLER)Trame.cpp \
		$(EVENT_ENTITY)AEntity.cpp \
		$(EVENT_ENTITY)EntityFactory.cpp \
		$(EVENT_ENTITY)AStaticEntity.cpp \
		$(EVENT_ENTITY)AAnimateEntity.cpp \
		$(SRC_PATH)Map.cpp \
		$(SRC_PATH)Rect.cpp \
		$(SRC_PATH)utils.cpp \
		$(SRC_PATH)Config.cpp \
		$(EVENT)Snake.cpp \
		$(EVENT)SnakePart.cpp \
		$(EVENT)TheGame.cpp \
		$(EVENT)Wall.cpp \
		$(EVENT)Floor.cpp \
		$(EVENT)Food.cpp \
		$(SRC_PATH)main.cpp \
		$(SRC_PATH)Debug.cpp \
		$(LIBRARY)Engine.cpp \



OBJ	=	$(SRC:.$(SRC_EXT)=.$(OBJ_EXT))

INC	=	-I $(INC_PATH)

CC	=	g++

CPPFLAGS	+=	-Wall -W $(INC) -g -ldl


# Rules

all:	$(NAME)

%.$(OBJ_EXT): %.$(SRC_EXT)
	$(CC) -o $@ -c $< $(INC) $(CPPFLAGS)

$(NAME):	$(OBJ)
	$(CC) -o $@ $^ $(INC) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

.PHONY:	clean fclean

## END
