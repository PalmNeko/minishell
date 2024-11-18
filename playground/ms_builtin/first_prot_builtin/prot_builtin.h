#ifndef PROT_BUILTIN_H
# define PROT_BUILTIN_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

int	prot_cd(const char *path);
int	prot_pwd(void);

#endif // #PROT_BUILTIN_H