NAME = app
GCC = gcc
SRC = *.c mod/*.c
FLGS =  -I./includes -I./lib -L./lib  -lft -lsf `pkg-config --cflags --libs gtk+-3.0`
OBJS = ${SRC:.c=.o}

all: ${NAME}

${NAME}:
	${GCC} -o ${NAME} ${SRC} ${FLGS}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

git: fclean
	git add .
	git commit -m ${NAME}
	git push -u origin HEAD

re: fclean all
    