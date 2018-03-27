/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Player controls
*/

#include "lemipc.h"

void	move_player(enum direction move_dir, player_t *player, int **map)
{
	int posx = player->posx;
	int posy = player->posy;

	switch (move_dir) {
		case UNDEFINED:
			return;
		case UP:
			if (posx - 1 < 0)
				return;
			if (map[posx - 1][posy] == 0)
				player->posx -= 1;
			break;
		case RIGHT:
			if (posy + 1 >= MAP_HEIGHT)
				return;
			if (map[posx][posy + 1] == 0)
				player->posy += 1;
			break;
		case DOWN:
			if (posx + 1 >= MAP_WIDTH)
				return;
			if (map[posx + 1][posy] == 0)
				player->posx += 1;
			break;
		case LEFT:
			if (posy - 1 < 0)
				return;
			if (map[posx][posy - 1] == 0)
				player->posy -= 1;
			break;
	}
	map[posx][posy] = 0;
	map[player->posx][player->posy] = player->team;
}