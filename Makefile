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
LDFALGS := -fsanitize=address
CPPFLAGS = $(foreach include,$(INCLUDES_DIR),-iquote $(include))

MKDIR := mkdir
INCLUDES_DIR := includes
#######

NAME := malloc

OBJ_DIR := objs
SRCS := \
	constants.c \
	create_zone.c \
	test.c \
	assert_create_zone.c \
	get_first_fit.c \
	free_node_get.c \
	free_node.c \
	alloc_zone_get.c
OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))
HEADER_DIR := includes
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJS): $(OBJ_DIR)/%.o: %.c Makefile $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $@
