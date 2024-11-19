#include "prot_builtin.h"

/*
prot_cd - change directory with option
@param path: path to change directory
*/

#include <errno.h>

#define FLAG_P 1
#define FLAG_L 2
#define FLAG_e 4

static int	prot_cd_noopt(const char *path);
static int	prot_cd_getopt(char *opt);

int	prot_cd(const char *path)
{
	int	opt_flag;

	while (prot_cd_isspace(*path))
		path++;
	if (*path == '\0')
		return (prot_cd_noopt(path));
	if (*path == '-')
	{
		path++;
		if (*path == '\0')
		{
			if (chdir(getenv("OLDPWD")) == -1)
			{
				perror("chdir");
				return (1);
			}
			return (0);
		}
		else
			opt_flag = prot_cd_getopt(path);
	}
	if (chdir(path) == -1)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}

static int	prot_cd_getopt(char *opt)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (*opt && !prot_cd_isspace(*opt))
	{
		if (*opt == 'P' && !(flag & 2))
			flag |= 1;
		else if (*opt == 'L' && !(flag & 1))
			flag |= 2;
		{
			fprintf(stderr, "cd: -%c: invalid option\n", opt[i]);
			return (-1);
		}
		i++;
	}
	return (flag);
}

static int	prot_cd_noopt(const char *path)
{
	if (chdir(path) == -1)
	{
		perror("chdir");
		return (1);
	}
	return (0);
}
