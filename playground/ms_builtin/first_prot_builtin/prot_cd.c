#include "prot_builtin.h"

/*
prot_cd - change directory with option
@param path: path to change directory
*/

static int	prot_cd_noopt(const char *path);
static int	prot_cd_getopt(char *opt);

int	prot_cd(const char *path)
{
	int		opt_flag;
	int		symlink_flag;
	char	buf[1024];

	opt_flag = 0;
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
		{
			opt_flag = prot_cd_getopt(path);
			if (opt_flag == -1)
				return (1);
			path++;
			while (*path && prot_cd_isspace(*path))
				path++;
			if (*path == '\0')
				return (prot_cd_noopt(path));
		}
	}
	if (chdir(path) == -1)
	{
		perror("chdir");
		return (1);
	}
	// PWDを書き換える場合にフルパスにする必要がある。
	printf("opt_flag: %d\n", opt_flag);
	if (opt_flag)
		setenv("PWD", path, 1);
	else
		setenv("PWD", getcwd(buf, 1024), 1);
	return (0);
}

static int	prot_cd_getopt(char *opt)
{
	int			flag;
	int			i;
	const char	*opt_str = (const char *)opt;

	flag = 0;
	i = 0;
	while (*opt && !prot_cd_isspace(*opt))
	{
		if (*opt == 'P')
			flag = 1;
		else
		{
			fprintf(stderr, "cd: -%s: invalid option\n", opt_str);
			return (-1);
		}
		opt++;
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

static bool	prot_cd_issymlink(const char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) == -1)
	{
		perror("lstat");
		return (false);
	}
	if (S_ISLNK(buf.st_mode))
		return (true);
}
