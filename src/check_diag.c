/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** Checks for collision
*/

#include "lemipc.h"

int check_diag_up_left(int **map, int posx, int posy)
{
	if (posx > 0 && posy > 0)
		return (map[posx - 1][posy - 1]);
	return (0);
}

int check_diag_up_right(int **map,int posx, int posy)
{
	if (posx > 0 && posy < MAP_HEIGHT)
		return (map[posx - 1][posy + 1]);
	return (0);
}

int check_diag_down_left(int **map, int posx, int posy)
{
	if (posx < MAP_WIDTH && posy > 0)
		return (map[posx + 1][posy - 1]);
	return (0);
}

int check_diag_down_right(int **map,int posx, int posy)
{
	if (posx < MAP_WIDTH && posy < MAP_HEIGHT)
		return (map[posx + 1][posy + 1]);
	return (0);
}