/*
** EPITECH PROJECT, 2019
** Hunter2.0
** File description:
** game
*/

#include "game.h"
#include "include.h"

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

// INITATION FUNCTION
void colision_with_wall_condition(game_t *game, int count);
char *my_strcat(char *dest, char const *src);
char *generate_random_filepath(int);
int my_strlen(const char *);
void text_init(game_t *);
void check_shoot(game_t *game);
void text_init_biggest_score(game_t *);
void init_game(game_t *);
void music_init(game_t *);
void create_player(game_t *);
void init_launch(game_t *);
void init_parallax(game_t *, char *, char *);
int menu_manage(game_t *);
void init_parallax_ground(game_t *, char *);
void init_icon(game_t *);
void jump(game_t *);
void object_init(object_t *, char *, int, int);
void button2_init(game_t *, char *, int, int);
void button3_init(game_t *, char *, int, int);
void init_parallax_planet(game_t *, char *);
void generate_second_planet(game_t *);
void recreate_sprite(game_t *, int);
void create_obstacle(int, int, game_t *, char *);
void create_ground(int, int, game_t *);
void create_ennemy(game_t *, int);
void spawn_ennemy(game_t *);
int random_map_generation(game_t *);
int create_obstacle_s(int, int, game_t *, char *);
void regenerate_platform(game_t *, int);
void generate_ships(game_t *, int);
char *generate_random_ships(int);
int checking_size(char *);
int malloc_struct_table(game_t *);
void check_number_on_map(game_t *);
int checking_map_content(game_t *, char *);
int polling_event(game_t *, sfEvent, int);
int check_file_content(char *);
int check_click_on_button(game_t *, object_t, sfEvent);
int menu_mouse_click(game_t *, sfEvent, int);

//DRAWING FUNCTION
void update_games(game_t *);
void paralax_check_ground(game_t *);
char *generate_random_(int);
void generate_planet(game_t *, int);

//EVENT FUNCTION
void poll_event(sfEvent, game_t *);
void manage_game_advancing(game_t *);
void icon_check(game_t *);
void wall_check(game_t *);
void change_menu_background(game_t *, char *);
void check_shoot(game_t *);
void check_colision_wall(game_t *);
int check_gravity(game_t *);
void check_colision_ennemy(game_t *);
void game_loop(game_t *);

//ANIMATION FUNCTION
void move_icon(game_t *);
void move_player_rect(game_t *);
void check_rect(game_t *);
void paralax_move(game_t *);
void paralax_move_ground(game_t *);
void move_wall(game_t *);
void paralax_move_planet(game_t *);
void check_shoot(game_t *);
void check_bullet_colision(game_t *);
void update_shoot(game_t *);
void draw_and_move_objects(game_t *);
void update_map_and_score(game_t *);
void check_falling(game_t *);
void falling_gestion(game_t *);
void victory_check(game_t *);

//SCORE FUNCTION
void get_biggest_score(game_t *);
void set_biggest_score(game_t *);

//LIBRARY FUNCTION
int my_getnbr(const char *);
int my_strlen(const char *);
char *digit_to_char(int);
int generate_number(int, int);
int how_to_play(game_t *);

//START AND STOP FUNCTION
int sfml_game_start(char **);
void launching_game(game_t *);
void start_game(game_t *);
void destroy_game(game_t *);
void game_over(game_t *, char *, sfMusic *);
void paralax_destroy(game_t *);
void paralax_destroy_ground(game_t *);
void paralax_planet_destroy(game_t *);
void paralax_destroy_ground(game_t *);
void paralax_destroy(game_t *);
void destroy_object(object_t);
void destroy_shoot(game_t *);
int restart_game(game_t *);
int init_map(char *, game_t *);
void check_number_on_map(game_t *);
int my_strcmp(char const *, char const *);
void ground_destroy(game_t *);
void wall_destroy(game_t *);
sfVector2f get_position_spawn(game_t *, int);

#endif /* !PROTOTYPES_H_ */