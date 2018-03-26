/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** map
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/shm.h>
#include "lemipc.h"

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
	} else {
		map = shmat(player->shmid, NULL, SHM_R | SHM_W);
		if (map == (void*)-1)
			return (NULL);
		map = create_map(map, false);
	}
	return (map);
}