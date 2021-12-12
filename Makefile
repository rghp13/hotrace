define HEADER
  _  _     _                   
 | || |___| |_ _ _ __ _ __ ___ 
 | __ / _ \  _| '_/ _` / _/ -_)
 |_||_\___/\__|_| \__,_\__\___|
                               
endef
export HEADER

PATH_SRC					=	./srcs
PATH_HEAD					=	./includes
SRC_NAME					=	main.c gnl.c utils.c utils2.c hash.c ft_parse.c search.c free.c

NAME						=	hotrace
OBJ_NAME					=	$(SRC_NAME:.c=.o)
CC							=	gcc
RM							=	rm -f
CFLAG						=	-g -Wall -Wextra -Werror
SRC							=	$(addprefix $(PATH_SRC)/,$(SRC_NAME))
OBJ							=	$(addprefix $(PATH_SRC)/,$(OBJ_NAME))

.c.o:
								@${CC} ${CFLAG} -I${PATH_HEAD} -c $< -o ${<:.c=.o}
								@echo "[ OK ] ${<:.s=.o}"
${NAME}:						${OBJ}
								@${CC} $^ -o $@ ${CFLAG}
								@echo "[ COMPLETE ]"
								@echo "$$HEADER"
all:							${NAME}

clean:
								@${RM} ${OBJ}
								@echo "\n[ OK ]     *.o files deleted"
fclean:							clean
								@${RM} ${NAME}
								@echo "[ OK ]     ${NAME}     deleted"
re:								fclean ${NAME}
.PHONY:							all clean fclean re