# settings
NAME     = test.out
SRC      = $(shell find . -name "*.c")
CXX      = g++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -pthread -lgtest_main -lgtest

CACHEDIR = cache

# generate from above variable
OBJS    = $(addprefix $(CACHEDIR)/,$(SRC:.cpp=.o))
DEPS    = $(addprefix $(CACHEDIR)/,$(SRC:.cpp=.d))

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

$(CACHEDIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MF $(CACHEDIR)/$*.d -o $@ -c $<
