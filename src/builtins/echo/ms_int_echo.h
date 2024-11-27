#ifndef MS_INT_ECHO_H
# define MS_INT_ECHO_H

# include <stddef.h>
# include <stdbool.h>

bool	ms_has_opt(char *const argv[], const char *opt);
char	*ms_join_ntp(char *const ntp[], const char *pad);

#endif
