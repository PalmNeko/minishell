# settings
NAME     = lexical_analyze.out
SRC      = $(shell find . -name "*.c")
CXX      = cc
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP

CACHEDIR = cache

# generate from above variable
OBJS    = $(addprefix $(CACHEDIR)/,$(SRC:.c=.o))
DEPS    = $(addprefix $(CACHEDIR)/,$(SRC:.c=.d))

# PHONY rules
all: $(NAME)

clean:
	rm -rf $(CACHEDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

sanitize: LDFLAGS += -fsanitize=leak
sanitize: CXXFLAGS += -fsanitize=leak
sanitize: debug

debug: LDFLAGS += -g -O0
debug: CXXFLAGS += -g -O0
debug: all

show:
	@echo variables value
	@printf "%s:\n\t%s\n" "NAME" "$(NAME)"
	@printf "%s:\n\t%s\n" "SRC" "$(SRC)"

-include $(DEPS)

# file rules
$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

$(CACHEDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MF $(CACHEDIR)/$*.d -o $@ -c $<
