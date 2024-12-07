#include <readline/readline.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	year;

	if (isatty(0) && isatty(2))
	{
		printf("Enter a year: ");
		fflush(stdout);
	}
	scanf("%d", &year);
	if (year == 2024)
	{
		printf("The year %d is a this year.\n", year);
	}
	else
	{
		printf("The year %d is not a this year.\n", year);
	}
	return (0);
}
