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
LIBS := rbtree list utils itoa string d_list
INCLUDES_DIR := includes $(foreach lib,$(LIBS), $(lib)/includes)
#######

NAME := libft_malloc.so
LIBS_FILES := $(foreach lib,$(LIBS), $(lib)/lib$(lib).a)

OBJ_DIR := objs
TEST_DIR := tests
TEST_SRC_DIR := test_src
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.c)
TESTS := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%.passed,$(TEST_SRC))
TEST_EXE := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%,$(TEST_SRC))
options := CFLAGS

SRCS := \
	alloc_tiny_small.c \
	alloc_zone_cmp.c \
	alloc_zone_data_struct.c \
	alloc_zone_get.c \
	alloc_zone_get_2.c \
	alloc_zone_get_space.c \
	alloc_zone_get_space.c \
	alloc_zone_print.c \
	assert_create_zone.c \
	compute_pointers_offsets.c \
	constants.c \
	create_zone.c \
	free.c \
	free_node.c \
	free_node_get.c \
	free_node_get_addresses.c \
	get_first_fit.c \
	globals.c \
	malloc.c \
	node_size_constants.c \
	page_size_constants.c \
	realloc.c \
	show_alloc_mem.c \
	size_category.c

OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))
HEADER_DIR := includes
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

$(NAME): $(OBJS) $(LIBS_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(LIBS_FILES): force
	$(MAKE) -C $(dir $@) $(foreach opt,$(options),'$(opt)=$($(opt))')

.PHONY: force

$(NAME): CFLAGS := $(CFLAGS) -fPIC

$(OBJS): $(OBJ_DIR)/%.o: %.c Makefile $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) $(TEST_DIR):
	$(MKDIR) $@

$(TEST_EXE): $(TEST_DIR)/%: $(TEST_SRC_DIR)/%.c $(NAME) $(LIBS_FILES) | $(TEST_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(TESTS): %.passed:% | $(TEST_DIR)
	./$< $(TEST_OUT)
	touch $@

test: $(TESTS)

.PHONY: test


##### Special targets

.DELETE_ON_ERROR:
