NAME = so_long
NAMEB = so_long_bonus
HEADER = so_long.h
HEADERB = so_long_bonus.h

SRC = get_next_line/get_next_line_utils.c \
	parcing.c \
	get_next_line/get_next_line.c \
	so_long.c \
	lib.c \
	lib2.c \
	movse.c \
	draw_map.c \
	backtrakin.c \
	tols_so_long.c \
	parc.c \

 BSRC = so_long_bonus.c \
 	get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line.c \
	parcing_bonus.c \
	lib.c \
	lib2.c \
	movse_bonus.c \
	draw_map.c \
	backtrakin.c \
	tols_so_long.c \
	parc.c \



CC = cc
CFLAGS =  -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

all: $(NAME)

bonus : $(NAMEB)

$(NAME): $(SRC) $(HEADER)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAMEB): $(BSRC) $(HEADERB)
	@$(CC) $(CFLAGS) $(BSRC) -o $(NAMEB)

clean:
	@$(RM) $(NAME) $(NAMEB)

fclean: clean

re: fclean all