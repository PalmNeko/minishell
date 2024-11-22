#include "prot_builtin.h"

static size_t	count_words(const char *str);
char	**prot_built_split(char *str)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	ret = malloc(sizeof(char *) * count_words(str) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
		{
			ret[j] = malloc(sizeof(char) * 1024);
			k = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
				ret[j][k++] = str[i++];
			ret[j][k] = '\0';
			j++;
		}
	}
	ret[j] = NULL;
	return (ret);
}

bool	prot_cd_isspace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static size_t	count_words(const char *str)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && prot_cd_isspace(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !prot_cd_isspace(str[i]))
			i++;
	}
	return (count);
}