#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t	flag = 0;

void	sigint_handler(int sig)
{
	flag = 1;
	printf("乗っ取ったよ\n");
}

// int	my_event_hook(void)
// {
// 	rl_on_new_line();
// 	return (0);
// }

int	main(void)
{
	struct sigaction	sa;
	char				*line;

	// シグナルハンドラの設定
	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	// SIGINTシグナルのハンドラを登録
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (1);
	}
	// rl_event_hook = &my_event_hook;
	for (;;)
	{
		line = readline("prompt> ");
		// Ctrl-Dを押すとEOFだけを送りNULL
		if (line == NULL)
			break ;
		add_history(line);
		printf("line: %s\n", line);
		free(line);
	}
	return (0);
}
