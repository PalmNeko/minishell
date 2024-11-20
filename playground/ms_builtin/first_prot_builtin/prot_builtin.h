#ifndef PROT_BUILTIN_H
# define PROT_BUILTIN_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

int		prot_builtin(void);

int		prot_cd(const char *path);
int		prot_pwd(void);

// prot_utils.c
char	**prot_built_split(char *str);
bool	prot_cd_isspace(const char c);

#endif // #PROT_BUILTIN_H