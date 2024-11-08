#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	sigint_handler(int sig)
{
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(void)
{
	char	*line;

	signal(SIGINT, sigint_handler);
	while (1)
	{
		// プロンプトを表示して入力を待機
		line = readline("prompt> ");
		if (line == NULL)
		{
			printf("\n");
			break ;
		}
		if (*line)
		{
			add_history(line);
		}
		printf("入力された行: %s\n", line);
		free(line);
	}
	rl_clear_history();
	return (0);
}
