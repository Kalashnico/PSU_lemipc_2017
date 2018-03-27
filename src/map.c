/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** map
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <sys/shm.h>
#include "lemipc.h"

int has_won(int **map)
{
	int team = 0;

	for (int x = 0; x < MAP_WIDTH; ++x) {
		team = has_won_inner_loop(map, team, x);
		if (team == -1)
			return (0);
	}
	return (team);
}

void display_map(int **map)
{
	printf("------------------------------\n");
	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++)
			printf("%d", map[x][y]);
		printf("\n");
	}
	printf("------------------------------\n");
}

void put_player_on_map(player_t *player, int **map)
{
	if (map[player->posx][player->posy] == 0)
		map[player->posx][player->posy] = player->team;
	else {
		srand(time(0));
		player->posx = rand() % MAP_WIDTH;
		player->posy = rand() % MAP_HEIGHT;
		put_player_on_map(player, map);
	}
}

int **create_map(void *memory, bool host)
{
	int **map = malloc(sizeof(int*) * MAP_HEIGHT * MAP_WIDTH);

	if (!map)
		return (NULL);
	for (int x = 0; x < MAP_WIDTH; ++x) {
		map[x] = &((int*)memory)[MAP_HEIGHT * x];
		if (host)
			memset(map[x], 0, MAP_HEIGHT);
	}
	return (map);
}

int **load_map(player_t *player)
{
	void *map;

	player->shmid = shmget(player->key, (MAP_HEIGHT * MAP_WIDTH),
		SHM_R | SHM_W);
	if (player->shmid == -1) {
		player->shmid = shmget(player->key, (MAP_HEIGHT * MAP_WIDTH),
			IPC_CREAT | SHM_R | SHM_W);
		map = shmat(player->shmid, NULL, SHM_R | SHM_W);
		if (map == (void*)-1)
			return (NULL);
		map = create_map(map, true);
		player->is_host = true;
	} else {
		map = shmat(player->shmid, NULL, SHM_R | SHM_W);
		if (map == (void*)-1)
			return (NULL);
		map = create_map(map, false);
	}
	return (map);
}
