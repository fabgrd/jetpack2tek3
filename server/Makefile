##
## EPITECH PROJECT, 2022
## jetpack
## File description:
## Makefile
##

ROOT	=		.

SRC_DIR	=		src

BUILD	=		..

CC		=		gcc

NAME	=		serverJ2T3

REAL	=		$(ROOT)/build

MAIN	=		$(SRC_DIR)/main.c

SRC		=		$(SRC_DIR)/server.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/args.c \
				$(SRC_DIR)/client.c \
				$(SRC_DIR)/cmd.c \
				$(SRC_DIR)/network/id.c \
				$(SRC_DIR)/network/broadcast.c \
				$(SRC_DIR)/game/engine.c \
				$(SRC_DIR)/game/physic.c \
				$(SRC_DIR)/utils/array.c \
				$(SRC_DIR)/utils/client.c \
				$(SRC_DIR)/utils/my_str_split.c

TEST_SRC = 		$(wildcard tests/Test_*.c) $(wildcard tests/*/Test_*.c)

CFLAGS	=		-I $(ROOT)/include $(EFLAGS) -g3

LFLAGS	=		-L $(ROOT)/lib/

EFLAGS	=		-Wall -Wextra  -Wpedantic #-Werror

LIB 	=		lib/%.a

DEBUG_FLAG	=	--no-print-directory

V		=		@

OBJS	=		$(patsubst $(SRC_DIR)/%.c, $(REAL)/%.o, $(SRC) $(MAIN))

#COLOR
WHITE	=	\e[0m
RED		=	\e[1;31m
GREEN	=	\e[1;32m
ORANGE	=	\e[1;33m
BLUE	=	\e[1;34m
PURPLE  = 	\033[35m
CYAN    =	\033[36m
YELLOW	=	\e[1;33m

all: intro $(NAME)

intro:
	$(V) printf "$(RED)+------------------------------+\n$(WHITE)"
	$(V) printf "$(RED)|          ServerJ2T3          |\n$(WHITE)"
	$(V) printf "$(RED)+------------------------------+\n\n$(WHITE)"

$(NAME): $(REAL)/$(NAME)
	$(V) cp $(REAL)/$(NAME) $(BUILD)
	$(V) printf "$(PURPLE)\nDup $(GREEN)$(PURPLE)$(NAME)$(WHITE)$(PURPLE) into root directory.$(WHITE)\n"
	$(V) printf "$(GREEN)Project compilation success\n\n\n$(WHITE)"
$(REAL)/$(NAME): mkobj
	$(V) printf "$(YELLOW)===== LIBRARIES COMPILATION =====\n$(WHITE)"
	$(V) make mklib $(DEBUG_FLAG)
	$(V) printf "$(GREEN)[OK]$(PURPLE) Linking obj and libraries.$(WHITE)\n"
	$(V) $(CC) -o $(REAL)/$(NAME) $(OBJS) $(LFLAGS) $(CSFMLFLAGS)
	$(V) printf "$(GREEN)[OK]$(PURPLE) Binary link done.$(WHITE)\n"

$(REAL)/%.o: $(SRC_DIR)/%.c | $(REAL)
	$(V) mkdir -p $(dir $@)
	$(V) printf "$(PURPLE)Compiling $(GREEN)$(PURPLE)[$(WHITE)$(PURPLE)$(notdir $<)$(GREEN)$(PURPLE) -> $(CYAN)$(notdir $@)$(GREEN)$(PURPLE)]\n$(WHITE)"
	$(V) $(CC) -o $@ -c $< $(CFLAGS) $(LFLAGS)

mkobj: $(OBJS)
	$(V) printf "$(GREEN)====== SOURCES COMPILED ======\n\n$(WHITE)"

mklib: #lib/libprintf.a	lib/libmy.a
	$(V) printf "$(GREEN)===== LIBRARIES COMPILED =====\n\n$(WHITE)"

lib/lib%.a:
	$(V) $(MAKE) -C lib/$* $(DEBUG_FLAG)

rmlib: #rm/lib/libprintf.a	rm/lib/libmy.a
	$(V) printf "$(YELLOW)===== LIBRARIES CLEANED =====\n\n$(WHITE)"

rm/lib/lib%.a:
	$(V) $(MAKE) -C lib/$* fclean $(DEBUG_FLAG)


$(REAL):
	$(V) mkdir $@

clean:
	$(V) printf "$(ORANGE)Removing object files.$(WHITE)\n"
	$(V) rm -rf $(OBJS) .input.txt
	$(V) printf "$(ORANGE)Removing gcno files.$(WHITE)\n"
	$(V) rm -rf *.gcno
	$(V) printf "$(ORANGE)Removing gcda files.$(WHITE)\n"
	$(V) rm -rf *.gcda

fclean:	clean
	$(V) printf "$(YELLOW)===== LIBRARIES CLEANUP =====\n$(WHITE)"
	$(V) make rmlib $(DEBUG_FLAG)
	$(V) printf "$(ORANGE)Removing binary file.$(WHITE)\n"
	$(V) rm -f $(REAL)/$(NAME)
	$(V) rm -f $(BUILD)/$(NAME)
	$(V) rm -rf $(REAL)
	$(V) printf "$(ORANGE)Removing test file.$(WHITE)\n"
	$(V) rm -rf unit_tests
	$(V) rm -rf tests/resources/temps/*.tmp


re:	fclean
	$(V) make --no-print-directory all

tests_run: fclean intro
	$(V) $(CC) -o unit_tests $(TEST_SRC) $(SRC) $(CFLAGS) -lcriterion --coverage
	$(V) ./unit_tests

.PHONY: clean fclean debug all re intro tests_run