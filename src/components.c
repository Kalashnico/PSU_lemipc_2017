/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** Components (map, player)
*/

#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "lemipc.h"

void free_ressources(player_t *player, int **map)
{
	free(player);
	free(map);
}

void clear_ipc(player_t *player)
{
	semctl(player->semid, 0, IPC_RMID);
	shmctl(player->shmid, 0, IPC_RMID);
}

int init_components(char *path, int team)
{
	int **map = NULL;
	player_t *player = NULL;

	player = init_player(player, team);
	if (player == NULL)
		return (84);
	player->key = ftok(path, 0);
	if (player->key == -1)
		return (84);
	map = load_map(player);
	if (map == NULL)
		return (84);
	create_player_sem(player);
	put_player_on_map(player, map);
	display_map(map);
	clear_ipc(player);
	free_ressources(player, map);
	return (0);
}