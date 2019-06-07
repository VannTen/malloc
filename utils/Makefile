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

LIB_NAME := utils

NAME := lib$(LIB_NAME).a

OBJ_DIR := objs
TEST_DIR := tests
TEST_SRC_DIR := test_src
TEST_SRC := $(wildcard $(TEST_SRC_DIR)/*.c)
TESTS := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%.passed,$(TEST_SRC))
TEST_EXE := $(patsubst $(TEST_SRC_DIR)/%.c,$(TEST_DIR)/%,$(TEST_SRC))

SRCS := \
	ft_memcpy.c \
	max.c

OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))
HEADER_DIR := includes
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

$(NAME): $(OBJS)
	ar -rcu $@ $^

$(OBJS): $(OBJ_DIR)/%.o: %.c Makefile $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) $(TEST_DIR):
	$(MKDIR) $@

$(TEST_EXE): $(TEST_DIR)/%: $(TEST_SRC_DIR)/%.c -l$(LIB_NAME) | $(TEST_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(TESTS): %.passed:% | $(TEST_DIR)
	./$< $(TEST_OUT)
	touch $@

test: $(TESTS)

.PHONY: test
