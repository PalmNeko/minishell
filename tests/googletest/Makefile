# settings
NAME     = test.out
SRC      = \
	$(shell find . -name "*.cpp" -o -name "*.c")
SRC_DIR  = ../../src
CXX      = g++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -g -O0 -I $(SRC_DIR)/include -I include
CC       = cc
CFLAGS   = $(CXXFLAGS)
LDFLAGS  = -L.
LDLIBS   = -lmsh -pthread -lgtest_main -lgtest

CACHEDIR = cache

# generate from above variable
# OBJS    = $(addprefix $(CACHEDIR)/,$(SRC:.c=.o))
OBJS    = $(SRC:%=$(CACHEDIR)/%.o)
DEPS    = $(OBJS:.o=.d)

# command
MK_MSH  = make -f libmsh.mk

# PHONY rules
all: $(NAME)

test: all
	printf "\e[32m%b\e[m" "[  gtests  ]\n"
	valgrind -q --leak-check=full --error-exitcode=12 ./$(NAME) --gtest_brief

clean:
	$(MK_MSH) clean
	rm -rf $(CACHEDIR)

fclean: clean
	$(MK_MSH) fclean
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
	@printf "%s:\n\t%s\n" "OBJS" "$(OBJS)"

-include $(DEPS)

# file rules
$(NAME): $(OBJS) libmsh.a
	$(CXX) $(LDFLAGS) -o $@ $(filter %.o,$^) $(LDLIBS)

libmsh.a: $(shell find $(SRC_DIR) -name "*.c" -not -name "main.c")
	$(MK_MSH)

$(CACHEDIR)/%.c.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<

$(CACHEDIR)/%.cpp.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
