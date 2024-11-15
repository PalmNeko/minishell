# settings
NAME     = libmsh.a
PROJECT_DIR = ../..
SRC_DIR  = $(PROJECT_DIR)/src
SRC      = $(shell find $(SRC_DIR) -name "*.c" -not -name "main.c")
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -MMD -MP -g -O0 -I $(SRC_DIR)/include

CACHEDIR = cache

# generate from above variable
OBJS     = $(subst ./,,$(subst ../,,$(SRC:%=$(CACHEDIR)/%.o)))
DEPSS    = $(OBJS:.o=.d)

# PHONY rules
all: $(NAME)

clean:
	make -C $(SRC_DIR) clean

fclean: clean
	make -C $(SRC_DIR) fclean
	rm -rf $(NAME)

re: fclean all

show:
	@echo variables value
	@printf "%s:\n\t%s\n" "NAME" "$(NAME)"
	@printf "%s:\n\t%s\n" "SRC" "$(SRC)"
	@printf "%s:\n\t%s\n" "OBJS" "$(OBJS)"

-include $(DEPS)

# file rules
$(NAME): $(OBJS)
	ar rcs $@ $(filter %.o,$^)

$(CACHEDIR)/%.c.o: $(PROJECT_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $<
