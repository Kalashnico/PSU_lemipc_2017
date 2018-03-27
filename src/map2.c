/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Map norm
*/

#include "lemipc.h"

int has_won_return(int **map, int x, int y, int team)
{
	if (map[x][y] != 0) {
		if (team == 0)
			return (map[x][y]);
		else if (team != map[x][y] && map[x][y] != 0)
			return (-1);
	}
	return (team);
}

int has_won_inner_loop(int **map, int team, int x)
{
	for (int y = 0; y < MAP_HEIGHT; ++y) {
		team = has_won_return(map, x, y, team);
		if (team == -1)
			return (-1);
	}
	return (team);
}