#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexer.h"
	#include "libms.h"
}

TEST(ms_lsa_set_heredoc, basic)
{
	t_lsa				*lsa;
	t_syntax_node		*syntax_analyzed;
	t_token				**tokens;
	t_lsa_redirection	*lsa_redirection;

	tokens = ms_lexical_analyze("echo test << word\nabc\nword\n");
	syntax_analyzed = ms_syntax_analyze(tokens);
	lsa = semantic_analyze(syntax_analyzed);

	lsa_redirection = lsa->lists[0]->pipeline->commands[0]->redirects[0];
	EXPECT_EQ(lsa_redirection->type, LSA_RD_HEREDOC);
	EXPECT_NE(lsa_redirection->delimiter, nullptr);
	EXPECT_NE(lsa_redirection->heredoc_input, nullptr);

	ms_destroy_ntp2((void **)tokens, ms_lexical_analyze_destroy_token_wrapper);
	ms_syntax_node_destroy(syntax_analyzed);
	ms_lsa_destroy(lsa);
}
