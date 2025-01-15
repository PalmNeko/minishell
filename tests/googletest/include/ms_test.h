#ifndef MS_TEST_H
# define MS_TEST_H

#include "syntax_analyze.h"

int	ms_capture(int fd, int pipe[2], int *stored_fd);
int	ms_uncapture(int fd, int pipe[2], int *stored_fd);
#endif
