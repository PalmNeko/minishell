#ifndef EXECUTION_TYPE_H

# define EXECUTION_TYPE_H

typedef enum e_state_in_command
{
	MIDDLE_COMMAND,
	FIRST_COMMAND,
	LAST_COMMAND,
	SINGLE_COMMAND,
}							t_state_in_pipeline;
#endif