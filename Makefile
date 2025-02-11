NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c pipex_utils.c split_shell.c split_shell_2.c

SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c split_shell_bonus.c split_shell_bonus_2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c pipex_utils_2_bonus.c

OBJ = ${SRCS:.c=.o}

OBJ_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT = libft/libft.a

RM = rm -rf

FLAG = .bonus

all: ${NAME}

${NAME}: ${LIBFT} ${OBJ}
	${CC} ${CFLAGS} $^ -o $@

bonus: ${LIBFT} ${OBJ_BONUS}
	${CC} ${CFLAGS} $^ -o ${NAME}

${LIBFT}:
	${MAKE} bonus -C ./libft

%_bonus.o: %_bonus.c pipex_bonus.h
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.c pipex.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all

.PHONY: clean