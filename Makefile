# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdehouck <rdehouck@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 10:07:42 by robindehouc       #+#    #+#              #
#    Updated: 2022/03/09 12:32:51 by rdehouck         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

# SOURCES / obj files
SOURCES			= 	main.c \
				struct.c \
				control.c \
				processing.c \
				utils.c \
				factory.c \
				key_manager.c \

OBJ			= $(addprefix $(OBJDIR),$(SOURCES:.c=.o))

# compiler
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

# mlx library
MLX			= ./miniLibX/
MLX_LIB		= $(addprefix $(MLX),mlx.a)
MLX_INC		= -I ./miniLibX
MLX_LNK		= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

# ft library
FT			= ./libft/
FT_LIB 		= $(addprefix $(FT),libft.a)
FT_INC 		= -I ./libft
FT_LNK 		= -L ./libft -l ft

# directories
SOURCESDIR		= ./sources/
INCDIR		= ./includes/
OBJDIR		= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SOURCESDIR)%.c
		$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FT)

$(MLX_LIB):
		@make -C $(MLX)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
		@rm -rf $(OBJDIR)
		@make -C $(FT) clean
		@make -C $(MLX) clean

fclean: clean
		@rm -rf $(NAME)
		@make -C $(FT) fclean

re: fclean all

.PHONY: all clean fclean re
