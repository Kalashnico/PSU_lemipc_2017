/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** Components (map, player)
*/

#include <sys/ipc.h>
#include "lemipc.h"

player_t *init_player(player_t *player, int team)
{
	player = malloc(sizeof(player_t));
	if (player == NULL)
		return (NULL);
	player->team = team;
	return (player);
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
	return (0);
}