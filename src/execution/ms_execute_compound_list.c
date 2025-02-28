#include "execution.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libms.h"

int ms_execute_compound_lists(t_lsa_list **lists)
{
	int ret;
	pid_t pid;

	ret = 0;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		ret = ms_execute_lists(lists);
		exit(ret);
	}
	waitpid(pid, &ret, 0);
	return (ret);
}
