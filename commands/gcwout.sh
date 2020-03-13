#!/bin/sh
# proot is project working directory. It is defined .vscode/tasks.json
gcc -Wall -Wextra -Werror ${proot}/main.c ${proot}/ft_*.c \
	${proot}/libft/*.c -o ${proot}/a.out && ${proot}/a.out
