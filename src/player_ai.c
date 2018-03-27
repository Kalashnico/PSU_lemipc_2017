/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Player AI
*/

#include "lemipc.h"

bool is_next_to_enemy(player_t *player, int **map)
{
	int next_to[8] = {check_up(map, player),
			check_right(map, player),
			check_down(map, player),
			check_left(map, player),
			check_diag_up_right(map, player),
			check_diag_down_right(map, player),
			check_diag_down_left(map, player),
			check_diag_up_left(map, player)};

	for (int i = 0; i < 8; ++i)
		if (next_to[i] != player->team && next_to[i] != 0)
			return (true);
	return (false);
}

void check_possible_move(player_t *player, int **map)
{
	if (is_next_to_enemy(player, map))
		return;
}