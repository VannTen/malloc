#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By:  <>                                        +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2019/03/29 13:16:58 by                   #+#    #+#             *#
#*   Updated: 2019/03/29 13:16:58 by                  ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CFLAGS := -g3 -Wall -Wextra -Werror -pedantic -fsanitize=address
LDFLAGS := -fsanitize=address
CPPFLAGS = $(foreach include,$(INCLUDES_DIR),-iquote $(include))

MKDIR := mkdir
INCLUDES_DIR := includes
#######

NAME := librbtree.a

OBJ_DIR := objs
TEST_DIR := tests
TEST_SRC_DIR := test_src
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.c)
TESTS := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%.passed,$(TEST_SRC))
TEST_EXE := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%,$(TEST_SRC))

SRCS := \
	btree_operations.c \
	rbtree_init.c \
	rbtree_ops.c \
	rbtree_delete.c \
	rbtree_delete_balance.c \
	rbtree_helpers.c \
	rbtree_test_helpers.c \
	rbtree_properties_checks.c \
	rbtree_properties_checks_2.c \
	rbtree_debug.c

OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))
HEADER_DIR := includes
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

$(NAME): $(OBJS)
	ar -rcu $@ $^

$(OBJS): $(OBJ_DIR)/%.o: %.c Makefile $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) $(TEST_DIR):
	$(MKDIR) $@

$(TEST_EXE): $(TEST_DIR)/%: $(TEST_SRC_DIR)/%.c -lrbtree | $(TEST_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(TESTS): %.passed:% | $(TEST_DIR)
	./$<
	touch $@

test: $(TESTS)

.PHONY: test
