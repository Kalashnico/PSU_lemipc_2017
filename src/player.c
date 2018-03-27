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

player_t *init_player(player_t *player, int team)
{
	player = malloc(sizeof(player_t));
	if (player == NULL)
		return (NULL);
	player->team = team;
	player->is_alive = true;
	player->is_host = false;
	srand(time(0));
	player->posx = rand() % MAP_WIDTH;
	player->posy = rand() % MAP_HEIGHT;
	return (player);
}
