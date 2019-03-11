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

INCLUDES_DIR := includes
#######

NAME := malloc

SRCS := create_zone.c test.c
OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(SRCS)))

$(OBJS): $(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@

$(OBJ_DIR):
	$(MKDIR) $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
