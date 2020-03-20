#!/bin/sh
# proot is project working directory. proot and active_file are defined
# .vscode/tasks.json
gcc -Wall -Wextra -Werror ${proot}/${active_file} -o ${proot}/a.out && \
${proot}/a.out
