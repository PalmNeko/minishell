#include <gtest/gtest.h>

extern "C" {
	#include "semantic_analyze.h"
	#include "semantic_analyze_internal.h"
	#include "syntax_analyze.h"
	#include "lexical_analyze.h"
	#include "libms.h"
}

TEST(Semantic_Analyze, LSA_WORDLIST_SUCCESS)
{
	t_lsa_word_list	*expect;
	t_lsa_word_list	*actual;
	t_syntax_node	*wordlist_node;
	t_token			**tokens;
	const char		*str;

	str = "word";
	tokens = ms_lexical_analyze(str);
	wordlist_node = ms_parse_word_list(tokens, 0);

	expect = (t_lsa_word_list *)malloc(sizeof(t_lsa_word_list));
	expect->word_list = wordlist_node;	

	actual = ms_lsa_word_list(wordlist_node);

	EXPECT_EQ(expect->word_list, actual->word_list);

	ms_lsa_wordlist_destroy(expect);
	ms_lsa_wordlist_destroy(actual);
	ms_syntax_node_destroy(wordlist_node);
	ms_destroy_ntp2((void**)tokens,  ms_destroy_token_wrapper);
}