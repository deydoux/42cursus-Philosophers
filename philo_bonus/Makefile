NAME				=	philo_bonus

SOURCES				=	get_ms_time.c					\
						init_philo/init_philo.c			\
						init_philo/init_semaphores.c	\
						init_philo/parse_args.c			\
						init_processes.c				\
						init_sleeper.c					\
						philo.c							\
						routine/routine.c				\
						utils/ft_bzero.c				\
						utils/ft_calloc.c				\
						utils/ft_memcpy.c				\
						utils/ft_putstr_fd.c			\
						utils/ft_strlcat.c				\
						utils/ft_strlcpy.c				\
						utils/ft_strlen.c

SOURCES_DIR			=	sources
INCLUDE_DIR			=	include
BUILD_DIR			=	build

CC					=	cc
CFLAGS				=	-I$(INCLUDE_DIR) -MD -Wall -Wextra -Werror -g
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
