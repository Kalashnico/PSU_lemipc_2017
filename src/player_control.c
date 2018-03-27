/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Player controls
*/

#include "lemipc.h"

void	move_player(enum direction dir, player_t *player, int **map)
{
	int posx = player->posx;
	int posy = player->posy;

	switch (dir) {
		case UP: if (map[posx - 1][posy] == 0)
				player->posx -= 1;
			break;
		case RIGHT: if (map[posx][posy + 1] == 0)
				player->posy += 1;
			break;
		case DOWN: if (map[posx + 1][posy] == 0)
				player->posx += 1;
			break;
		case LEFT: if (map[posx][posy - 1] == 0)
				player->posy -= 1;
			break;
	}
	map[posx][posy] = 0;
	map[player->posx][player->posy] = player->team;
}