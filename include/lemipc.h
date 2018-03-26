/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** lemipc
*/

#pragma once

#include <sys/types.h>

#define HELP_USAGE "USAGE\n\t./lemipc PATH TEAM_NUMBER\n"
#define HELP_PATH "\nDESCRIPTION\n\tPATH\tpath you'll give to ftok\n"
#define HELP_TEAM_NB "\tTEAM_NUMBER\tteam number of the current champion (greater than 0)\n"

#define MAP_HEIGHT 20
#define MAP_WIDTH 20

typedef struct player_s {
	key_t key;
	int shmid;
	int semid;
	int posx;
	int posy;
	int team;
}	player_t;
