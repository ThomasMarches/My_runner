##
## EPITECH PROJECT, 2019
## CSFML_Initiation
## File description:
## Makefile
##

NAME 	= 	my_runner

SRC		=	src/main.c \
			src/game.c \
			src/launch.c \
			src/create_player.c \
			src/music.c \
			src/poll_event.c \
			src/update_games.c \
			src/move_rect.c \
			src/generate_random_number.c \
			src/text_init.c \
			src/game_over.c \
			src/digit_to_char.c \
			src/biggest_score_get.c \
			src/my_getnbr.c \
			src/my_strlen.c \
			src/parallax.c \
			src/menu_manage.c \
			src/manage_game_advancing.c \
			src/icon.c \
			src/jump.c \
			src/destroy.c \
			src/wall.c \
			src/paralax_planet.c \
			src/generate_planet.c \
			src/object_init.c \
			src/shoot.c \
			src/restart_game.c \
			src/check_colision_wall.c \
			src/create_ground.c \
			src/init_map.c \
			src/my_strcmp.c \
			src/ground.c \
			src/draw_move_objects.c \
			src/update_score_and_map.c \
			src/ennemy.c \
			src/create_obstacle.c \
			src/random_map_generation.c \
			src/victory.c \
			src/malloc_struct_table.c \
			src/checking_map_content.c \
			src/check_number_on_map.c \
			src/destroy_object.c \
			src/how_to_play.c \
			src/my_strcat.c \
			src/get_position_spawn.c \
			src/check_shoot.c \

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-I./Include/ -Wno-deprecated

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio

clean:
		rm -f src/*.o
		rm -f $(NAME)

fclean: clean
		rm -f $(NAME)

re: 	fclean clean $(NAME)

debug:
		gcc -o $(NAME) $(OBJ) $(CFLAGS)
