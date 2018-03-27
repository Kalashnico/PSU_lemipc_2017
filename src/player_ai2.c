/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Player AI 2
*/

#include "lemipc.h"

bool is_next_to_enemy(int posx, int posy, int team, int **map)
{
	int next_to[8] = {check_up(map, posx, posy),
			check_right(map, posx, posy),
			check_down(map, posx, posy),
			check_left(map, posx, posy),
			check_diag_up_right(map, posx, posy),
			check_diag_down_right(map, posx, posy),
			check_diag_down_left(map, posx, posy),
			check_diag_up_left(map, posx, posy)};

	for (int i = 0; i < 8; ++i)
		if (next_to[i] != team && next_to[i] != 0)
			return (true);
	return (false);
}

int calculate_distances_ally(player_t *player,
				int **map,
				int x,
				int *distance_y)
{
	int distance_x = 0;

	for (int y = 0; y < MAP_HEIGHT; y++) {
		if (map[x][y] != player->team || map[x][y] == 0)
			continue;
		if (x == player->posx && y == player->posy)
			continue;
		if (!is_next_to_enemy(x, y, player->team, map))
			continue;
		if (absolute(x - player->posx) <
			((absolute(distance_x) == 0) ?
			(int)MAP_WIDTH : absolute(distance_x)))
			distance_x = x - player->posx;
		if (absolute(y - player->posy) <
			((absolute(*distance_y) == 0) ?
			(int)MAP_HEIGHT : absolute(*distance_y)))
			*distance_y = y - player->posy;
		}
	return (distance_x);
}

int calculate_distances_enemy(player_t *player,
				int **map,
				int x,
				int *distance_y)
{
	int distance_x = 0;

	for (int y = 0; y < MAP_HEIGHT; y++) {
		if (map[x][y] == player->team || map[x][y] == 0)
			continue;
		if (absolute(x - player->posx) <
			((absolute(distance_x) == 0) ?
			(int)MAP_WIDTH : absolute(distance_x)))
			distance_x = x - player->posx;
		if (absolute(y - player->posy) <
			((absolute(*distance_y) == 0) ?
			(int)MAP_HEIGHT : absolute(*distance_y)))
			*distance_y = y - player->posy;
		}
	return (distance_x);
}

bool check_player_stuck(player_t *player, enum direction move_dir)
{
	static int stuck_counter = 0;

	if (move_dir == LEFT && player->last_dir == RIGHT)
		stuck_counter++;
	else if (move_dir == RIGHT && player->last_dir == LEFT)
		stuck_counter++;
	if (stuck_counter >= 5) {
		stuck_counter = 0;
		return (true);
	}
	return (false);
}
