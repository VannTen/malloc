#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/03/11 14:43:41 by                   #+#    #+#             *#
#*   Updated: 2019/03/11 14:43:41 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CFLAGS := -g3 -Wall -Wextra -Werror -pedantic -fsanitize=address
LDFLAGS := -shared -fsanitize=address
CPPFLAGS = $(foreach include,$(INCLUDES_DIR),-iquote $(include))

MKDIR := mkdir
INCLUDES_DIR := includes rb_tree/includes list/includes
#######

NAME := libmalloc.so
LIBS := rbtree/librbtree.a list/liblist.a

OBJ_DIR := objs
TEST_DIR := tests
TEST_SRC_DIR := test_src
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.c)
TESTS := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%.passed,$(TEST_SRC))
TEST_EXE := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%,$(TEST_SRC))

SRCS := \
	alloc_zone_data_struct.c \
	alloc_zone_get.c \
	assert_create_zone.c \
	compute_pointers_offsets.c \
	constants.c \
	create_zone.c \
	free.c \
	free_node.c \
	free_node_get.c \
	get_first_fit.c \
	globals.c \
	malloc.c \
	node_size_constants.c \
	page_size_constants.c

OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))
HEADER_DIR := includes
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(LIBS): force
	$(MAKE) -C $(dir $@)

.PHONY: force

$(NAME): CFLAGS := $(CFLAGS) -fPIC
$(NAME): LDFLAGS := $(LDFLAGS) -shared

$(OBJS): $(OBJ_DIR)/%.o: %.c Makefile $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) $(TEST_DIR):
	$(MKDIR) $@

$(TEST_EXE): $(TEST_DIR)/%: $(TEST_SRC_DIR)/%.c -lmalloc | $(TEST_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(TESTS): %.passed:% | $(TEST_DIR)
	./$<
	touch $@

test: $(TESTS)

.PHONY: test
