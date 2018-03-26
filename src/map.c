/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** map
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include "lemipc.h"

int **create_map(void *memory)
{
    int **map = malloc(sizeof(int*) * MAP_HEIGHT * MAP_WIDTH);

    if (!map)
        return (NULL);
    for (int x = 0; x < MAP_WIDTH; ++x) {
        map[x] = &((int*)memory)[MAP_HEIGHT * x];
        memset(map[x], 0, MAP_WIDTH);
    }
    return (map);
}

int **load_map(t_player *player) 
{
    void *map;
    int shmid = shmget(player->key, (MAP_HEIGHT * MAP_WIDTH), SHM_R | SHM_W);

    if (shmid == -1) {
        player->shmid = shmget(player->key, (MAP_HEIGHT * MAP_WIDTH), IPC_CREAT | SHM_R | SHM_W);
        map = shmat(shmid, NULL, SHM_R | SHM_W);
        map = create_map(map);
    } else {
        player->shmid = shmid;
        map = shmat(shmid, NULL, SHM_R | SHM_W);
    }
    return (map);
}