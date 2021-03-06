/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** Components (map, player)
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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

void loop(player_t *player, int **map)
{
	while (!wait_for_connections(player->team, map));
	if (player->is_host)
		display_map(map);
	while ((player->is_alive || player->is_host) && has_won(map) == 0) {
		sleep(1);
		if (player->is_alive && check_killed(player, map))
			suicide(player, map);
		else if (player->is_alive)
			check_possible_move(player, map);
		if (player->is_host)
			display_map(map);
	}
	if (has_won(map) != 0 && player->is_host)
		printf("The team %d has won!\n", has_won(map));
}

int init_components(char *path, int team, bool cleanup)
{
	int **map = NULL;
	player_t *player = NULL;

	player = init_player(player, team, path);
	if (player == NULL)
		return (84);
	map = load_map(player);
	if (map == NULL)
		return (84);
	create_player_sem(player);
	put_player_on_map(player, map);
	if (cleanup)
		return (clear_ipc(player), free_ressources(player, map), 0);
	loop(player, map);
	if (player->is_host)
		clear_ipc(player);
	free_ressources(player, map);
	return (0);
}