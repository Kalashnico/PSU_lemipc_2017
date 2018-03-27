/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** Player
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lemipc.h"

player_t *create_player_sem(player_t *player)
{
	player->semid = semget(player->key, 1, SHM_R | SHM_W);
	if (player->semid == -1) {
		player->semid = semget(player->key, 1,
			IPC_CREAT | SHM_R | SHM_W);
		semctl(player->semid, 0, SETVAL, 1);
	} else {
		semctl(player->semid, 0, IPC_RMID);
		player->semid = semget(player->key, 1,
			IPC_CREAT | SHM_R | SHM_W);
	}
	return (player);
}

player_t *init_player(player_t *player, int team, char *path)
{
	player = malloc(sizeof(player_t));
	if (player == NULL)
		return (NULL);
	player->team = team;
	player->is_alive = true;
	player->key = ftok(path, 0);
	if (player->key == -1) {
		free(player);
		return (NULL);
	}
	srand(time(0));
	player->posx = rand() % MAP_WIDTH;
	player->posy = rand() % MAP_HEIGHT;
	player->is_host = false;
	return (player);
}

int find_occurence(const int map[8], int value)
{
	int nb_occurence = 0;

	for (int i = 0; i < 8; ++i) {
		if (value == map[i] && value != 0)
			++nb_occurence;
	}
	return (nb_occurence);
}

bool check_killed(player_t *player, int **map)
{
	int occurence = 0;
	int next_to[8] = {check_up(map, player->posx, player->posy),
			check_right(map, player->posx, player->posy),
			check_down(map, player->posx, player->posy),
			check_left(map, player->posx, player->posy),
			check_diag_up_right(map, player->posx, player->posy),
			check_diag_down_right(map, player->posx, player->posy),
			check_diag_down_left(map, player->posx, player->posy),
			check_diag_up_left(map, player->posx, player->posy)};

	for (int i = 0; i < 8; ++i) {
		occurence = find_occurence(next_to, next_to[i]);
		if (occurence > 1)
			return (true);
	}
	return (false);
}

int **suicide(player_t *player, int **map)
{
	semctl(player->semid, 0, IPC_RMID);
	player->is_alive = false;
	printf("A player of the team %d has died!\n", player->team);
	map[player->posx][player->posy] = 0;
	return (map);
}

