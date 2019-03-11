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

CFLAGS := -Wall -Wextra -Werror
CPPFLAGS = $(foreach include,$(INCLUDES_DIR),-iquote $(include))

MKDIR := mkdir
INCLUDES_DIR := includes
#######

NAME := malloc

OBJ_DIR := objs
SRCS := create_zone.c test.c assert_create_zone.c
OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJS): $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR) $@
