/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lemipc
*/

#pragma once

#include <stdbool.h>
#include <sys/types.h>

#define HELP_USAGE "USAGE\n\t./lemipc PATH TEAM_NUMBER\n"
#define HELP_PATH "\nDESCRIPTION\n\tPATH\tpath you'll give to ftok\n"
#define HELP_TEAM_NB "\tTEAM_NUMBER\tteam number of the current champion (greater than 0)\n"

#define MAP_HEIGHT 10
#define MAP_WIDTH 10

enum direction {
	UNDEFINED,
	UP,
	RIGHT,
	LEFT,
	DOWN
};

typedef struct player_s {
	key_t key;
	int shmid;
	int semid;
	int posx;
	int posy;
	enum direction last_dir;
	int team;
	bool is_host;
	bool is_alive;
}	player_t;

/* components.c */
int init_components(char*, int, bool);

/* map.c */
int has_won(int**);
void display_map(int**);
void put_player_on_map(player_t*, int**);
int **load_map(player_t*);

/* map2.c */
int has_won_inner_loop(int**, int, int);

/* player.c */
bool check_killed(player_t*, int**);
int **suicide(player_t*, int**);
player_t *create_player_sem(player_t*);
player_t *init_player(player_t*, int, char*);

/* player_ai.c */
void check_possible_move(player_t*, int**);

/* player_ai2.c */
int calculate_distances_ally(player_t*, int**, int, int*);
int calculate_distances_enemy(player_t*, int**, int, int*);
bool check_player_stuck(player_t*, enum direction);

/* player_control.c */
bool move_right(player_t*, int**, enum direction);
bool move_left(player_t*, int**, enum direction);
void move_player(enum direction, player_t *, int **);

/* check*.c */
int check_diag_up_left(int **, int, int);
int check_diag_up_right(int **, int, int);
int check_diag_down_left(int **, int, int);
int check_diag_down_right(int **, int, int);

int check_up(int **, int, int);
int check_down(int **, int, int);
int check_right(int **, int, int);
int check_left(int **, int, int);

/* utils.c */
bool wait_for_connections(int, int**);
int absolute(int);
