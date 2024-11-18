#include "prot_builtin.h"

static bool	prot_cd_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	prot_cd(const char *path)
{
	while (prot_cd_isspace(*path))
		path++;
	if (chdir(path) == -1)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}
