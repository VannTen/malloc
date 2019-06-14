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

CFLAGS := -g3 -Wall -Wextra -Werror -pedantic -DNDEBUG
LDFLAGS := -shared -lpthread
CPPFLAGS = $(foreach include,$(INCLUDES_DIR),-iquote $(include))

UNAME_S := $(shell uname -s)
MKDIR := mkdir
TIME_OPTIONS := $(if $(findstring Linux,$(UNAME_S)),-v,-l)
TIME := /usr/bin/time $(TIME_OPTIONS)
LIBS := rbtree utils itoa string d_list
INCLUDES_DIR := includes $(foreach lib,$(LIBS), $(lib)/includes)
#######

HOSTTYPE ?= $(shell uname -m)_$(shell uname -s)
NAME := libft_malloc.so
LIBS_FILES := $(foreach lib,$(LIBS), $(lib)/lib$(lib).a)

OBJ_DIR := objs
TEST_DIR := tests
TEST_SRC_DIR := test_src
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.c)
TESTS := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%.passed,$(TEST_SRC))
TEST_EXE := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%,$(TEST_SRC))
PERF_TEST_DIR := perfs_tests_result
PERF_TEST_SRC_DIR := perf_tests_src
PERF_TEST_SRC := $(wildcard $(PERF_TEST_SRC_DIR)/*.c)
PERF_TESTS := $(patsubst $(PERF_TEST_SRC_DIR)/%.c,$(PERF_TEST_DIR)/%.passed,$(PERF_TEST_SRC))
PERF_TEST_EXE := $(patsubst $(PERF_TEST_SRC_DIR)/%.c,$(PERF_TEST_DIR)/%,$(PERF_TEST_SRC))
options := CFLAGS

SRCS := \
	alloc_tiny_small.c \
	alloc_zone_cmp.c \
	alloc_zone_data_struct.c \
	alloc_zone_get.c \
	alloc_zone_get_2.c \
	alloc_zone_get_space.c \
	alloc_zone_print.c \
	alloc_zone_sanity_checks.c \
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
	malloc_lock.c \
	malloc_sanity_checks.c \
	malloc_size.c \
	node_size_constants.c \
	other_alloc.c \
	page_size_constants.c \
	realloc_intern.c \
	show_alloc_mem.c \
	size_category.c

OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))
HEADER_DIR := includes
HEADERS := \
	includes/alloc_zone.h \
	includes/bool.h \
	includes/constants.h \
	includes/free_node.h \
	includes/intern_alloc_helpers.h \
	includes/malloc.h \
	includes/malloc_lock.h \
	includes/malloc_structures.h \
	includes/small_tiny_alloc.h

$(NAME): %.so : | %_$(HOSTTYPE).so
	ln -s $| $@

$(basename $(NAME))_$(HOSTTYPE).so: $(OBJS) $(LIBS_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(LIBS_FILES): force
	$(MAKE) -C $(dir $@) $(foreach opt,$(options),'$(opt)=$($(opt))')

.PHONY: force

$(NAME): CFLAGS := $(CFLAGS) -fPIC
$(NAME): LDFLAGS += $(CFLAGS) -fPIC

$(OBJS): $(OBJ_DIR)/%.o: %.c Makefile $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) $(TEST_DIR) $(PERF_TEST_DIR):
	$(MKDIR) $@

$(TEST_EXE): $(TEST_DIR)/%: $(TEST_SRC_DIR)/%.c $(NAME) $(LIBS_FILES) | $(TEST_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lpthread

$(TESTS): %.passed:% | $(TEST_DIR)
	LD_LIBRARY_PATH=. ./$< $(TEST_OUT)
	touch $@

$(PERF_TEST_EXE): $(PERF_TEST_DIR)/%: $(PERF_TEST_SRC_DIR)/%.c | $(PERF_TEST_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

$(PERF_TESTS): %.passed:% $(NAME) | $(PERF_TEST_DIR)
	./run.sh $(TIME) ./$< 2>&1 >&- | grep -e "set size\|page\|context"
	$(TIME) ./$< 2>&1 >&- | grep -e "set size\|page\|context"

test: $(TESTS) perf_tests

perf_tests: $(PERF_TESTS)

.PHONY: test perf_tests $(PERF_TESTS)

# Cleaners

clean:
	$(RM) $(OBJS)
	$(foreach lib,$(LIBS),$(MAKE) -C $(lib) $@;)

fclean:
	$(RM) $(NAME) $(basename $(NAME))_$(HOSTTYPE).so
	$(foreach lib,$(LIBS),$(MAKE) -C $(lib) $@;)

re: fclean all
	$(foreach lib,$(LIBS),$(MAKE) -C $(lib) $@;)

all: $(NAME)

.DEFAULT_GOAL := all

.PHONY: clean fclean all re

ifneq '' '$(filter clean fclean re, $(MAKECMDGOALS))'
.NOTPARALLEL:

$(info Disabling parallelism for clean rules)
endif


##### Special targets

.DELETE_ON_ERROR:
