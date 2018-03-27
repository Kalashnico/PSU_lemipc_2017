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

#define MAP_HEIGHT 20
#define MAP_WIDTH 20

enum direction {
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

/* player.c */
bool check_killed(player_t*, int**);
int **suicide(player_t*, int**);
player_t *create_player_sem(player_t*);
player_t *init_player(player_t*, int, char*);

/* player_ai.c */
void check_possible_move(player_t*, int**);

/* player_control.c */
void	move_player(enum direction, player_t *, int **);

/* check*.c */
int check_diag_up_left(int **, player_t *);
int check_diag_up_right(int **, player_t *);
int check_diag_down_left(int **, player_t *);
int check_diag_down_right(int **, player_t *);

int check_up(int **, player_t *);
int check_down(int **, player_t *);
int check_right(int **, player_t *);
int check_left(int **, player_t *);
