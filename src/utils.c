/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Utils
*/

#include "lemipc.h"

bool wait_for_connections_inner(int host_team, int **map, int x)
{
	for (int y = 0; y < MAP_HEIGHT; y++) {
		if (map[x][y] != host_team && map[x][y] != 0)
			return (true);
	}
	return (false);
}

bool wait_for_connections(int host_team, int **map)
{
	for (int x = 0; x < MAP_WIDTH; x++) {
		if (wait_for_connections_inner(host_team, map, x))
			return (true);
	}
	return (false);
}

int absolute(int nbr)
{
	if (nbr >= 0)
		return (nbr);
	return (nbr * -1);
}