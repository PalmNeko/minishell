#ifndef SYNATX_ANALYZE_H
#define SYNATX_ANALYZE_H

#include "syntax_analyze_type.h"
#include "syntax_analyze_config.h"

t_syntax_node *ms_syntax_node_create(t_syntax_type type, int start_pos, int end_pos);

#endif // SYNATX_ANALYZE_H