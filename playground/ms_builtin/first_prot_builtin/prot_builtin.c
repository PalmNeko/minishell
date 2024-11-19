#include "prot_builtin.h"

int	prot_builtin(void)
{
	char	*line;
	int		ret;

	while (1)
	{
		line = readline("bulitin> ");
		if (!line)
			break ;
		if (line[0] == '\0')
			continue ;
		if (strncmp(line, "cd", 2) == 0)
			ret = prot_cd(line + 2);
		else if (strncmp(line, "pwd", 3) == 0)
			ret = prot_pwd();
		else if (strncmp(line, "$?", 2) == 0)
			printf("status: %d\n", ret);
		else
		{
			printf("%s : command not found\n", line);
			ret = 127;
		}
		free(line);
	}
	return (ret);
}
