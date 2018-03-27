/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Player controls
*/

#include "lemipc.h"

bool move_up(player_t *player, int **map, enum direction move_dir)
{
	if (player->posx - 1 < 0)
		return (false);
	if (map[player->posx - 1][player->posy] == 0) {
		player->posx -= 1;
		return (true);
	} else if (map[player->posx - 1][player->posy] == player->team
		&& move_dir == UP) {
		if (player->last_dir != LEFT
			&& move_right(player, map, move_dir))
			return (true);
		else if (player->last_dir != RIGHT
			&& move_left(player, map, move_dir))
			return (true);
	}
	return (false);
}

bool move_down(player_t *player, int **map, enum direction move_dir)
{
	if (player->posx + 1 >= MAP_WIDTH)
		return (false);
	if (map[player->posx + 1][player->posy] == 0) {
		player->posx += 1;
		return (true);
	} else if (map[player->posx + 1][player->posy] == player->team
		&& move_dir == DOWN) {
		if (player->last_dir != LEFT
			&& move_right(player, map, move_dir))
			return (true);
		else if (player->last_dir != RIGHT
			&& move_left(player, map, move_dir))
			return (true);
	}
	return (false);
}

bool move_right(player_t *player, int **map, enum direction move_dir)
{
	if (player->posy + 1 >= MAP_HEIGHT)
		return (false);
	if (map[player->posx][player->posy + 1] == 0) {
		player->posy += 1;
		return (true);
	} else if (map[player->posx][player->posy + 1] == player->team
		&& move_dir == RIGHT) {
		if (player->last_dir != UP
			&& move_up(player, map, move_dir))
			return (true);
		else if (player->last_dir != DOWN
			&& move_down(player, map, move_dir))
			return (true);
	}
	return (false);
}

bool move_left(player_t *player, int **map, enum direction move_dir)
{
	if (player->posy - 1 < 0)
		return (false);
	if (map[player->posx][player->posy - 1] == 0) {
		player->posy -= 1;
		return (true);
	} else if (map[player->posx][player->posy + 1] == player->team
		&& move_dir == LEFT) {
		if (player->last_dir != UP
			&& move_up(player, map, move_dir))
			return (true);
		else if (player->last_dir != DOWN
			&& move_down(player, map, move_dir))
			return (true);
	}
	return (false);
}

void move_player(enum direction move_dir, player_t *player, int **map)
{
	int posx = player->posx;
	int posy = player->posy;
	bool result = false;
	bool (*dirs[4]) (player_t *p, int **m, enum direction md);

	if (move_dir == UNDEFINED)
		return;
	dirs[0] = move_up;
	dirs[1] = move_right;
	dirs[2] = move_left;
	dirs[3] = move_down;
	result = (*dirs[move_dir - 1])(player, map, move_dir);
	if (result) {
		map[posx][posy] = 0;
		map[player->posx][player->posy] = player->team;
		player->last_dir = move_dir;
	}
}