#include "prot_builtin.h"

int	prot_pwd(void)
{
	char buf[1024];
	if (getcwd(buf, 1024) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	printf("%s\n", getenv("PWD"));
	return (0);
}