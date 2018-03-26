/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** Components (map, player)
*/

#include <stdlib.h>
#include <sys/ipc.h>
#include "lemipc.h"

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
	display_map(map);
	return (0);
}