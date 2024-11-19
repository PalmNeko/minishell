#include <stdio.h>
#include <string.h>
#include <unistd.h>

int is_meta(char *str)
{
	return (
		0
		|| strncmp(str, "|", 1) == 0
		|| strncmp(str, " ", 1) == 0
		|| 0);
}

int word(char *str, int *i)
{
	int start = *i;
	while(!is_meta(str + *i) && str[*i] != '\0')
		*i += 1;
	write(1, str + start, *i - start);
	write(1, "\n", 1);
	return (0);
}

int command(char *str, int* i)
{
	int start = *i;

	while(!is_meta(str + *i) && str[*i] != '\0')
		*i += 1;

	return (0);
}

int pipeline(char *str, int* i)
{
	command(str, i);
	while (is_meta(str + *i) && str[*i] != '\0')
	{
		write(1, "|\n", 2);
		(*i)++;
		command(str, i);
	}
	return (0);
}

int parse(char *str)
{
	int pos;
	pos = 0;
	pipeline(str, &pos);
	return (0);
}

int main(void)
{
	parse("adfsef|wefsdf|");
	return (0);
}
