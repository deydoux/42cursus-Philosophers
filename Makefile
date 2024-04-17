NAME				=	philo

SOURCES				=	init_table/init_mutexes.c	\
						init_table/init_philos.c	\
						init_table/init_table.c		\
						init_table/parse_args.c		\
						init_threads.c				\
						philo.c						\
						putstrs_fd.c				\
						routine/routine.c			\
						utils/ft_bzero.c			\
						utils/ft_calloc.c			\
						utils/ft_putstr_fd.c		\
						utils/ft_strlcat.c			\
						utils/ft_strlcpy.c			\
						utils/ft_strlen.c

SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
BUILD_DIR			=	build

CC					=	cc
CFLAGS				=	-I$(INCLUDE_DIR) -MD -Wall -Wextra -Werror -pthread -g
RM					=	rm -rf
MKDIR				=	mkdir -p

OBJECTS				=	$(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))
DEPENDENCIES		=	$(OBJECTS:.o=.d) $(BONUS_OBJECTS:.o=.d)

all					:	$(NAME)

-include 				$(DEPENDENCIES)

$(BUILD_DIR)/%.o	:	$(SOURCES_DIR)/%.c
	@$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -o $@ -c	$<

$(NAME)				:	$(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean				:
	$(RM) $(BUILD_DIR)

fclean				:
	$(RM) $(BUILD_DIR) $(NAME)

re					:	fclean all

.PHONY				:	all bonus clean fclean re
