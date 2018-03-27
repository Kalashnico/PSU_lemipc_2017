/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Player AI
*/

#include <time.h>
#include <stdlib.h>
#include "lemipc.h"

enum direction calculate_move_dir(player_t *player, int distance_x,
				int distance_y)
{
	enum direction move_dir = UNDEFINED;

	if (absolute(distance_x) > absolute(distance_y)) {
		if (distance_x < 0)
			move_dir = UP;
		else if (distance_x > 0)
			move_dir = DOWN;
	} else {
		if (distance_y < 0)
			move_dir = LEFT;
		else if (distance_y > 0)
			move_dir = RIGHT;
	}
	if (check_player_stuck(player, move_dir))
		return (calculate_move_dir(player, distance_y, distance_x));
	return (move_dir);
}

enum direction find_closest_attacking_ally(player_t *player, int **map)
{
	int distance_x = 0;
	int distance_y = 0;

	for (int x = 0; x < MAP_WIDTH; x++)
		distance_x = calculate_distances_ally(player, map, x,
							&distance_y);
	return (calculate_move_dir(player, distance_x, distance_y));
}

enum direction find_closest_enemy(player_t *player, int **map)
{
	int distance_x = 0;
	int distance_y = 0;

	for (int x = 0; x < MAP_WIDTH; x++)
		distance_x = calculate_distances_enemy(player, map, x,
							&distance_y);
	return (calculate_move_dir(player, distance_x, distance_y));
}

void check_possible_move(player_t *player, int **map)
{
	enum direction move_dir = UNDEFINED;

	move_dir = find_closest_attacking_ally(player, map);
	if (move_dir == UNDEFINED) {
		move_dir = find_closest_enemy(player, map);
		if (move_dir == UNDEFINED) {
			srand(time(0) + player->semid);
			move_dir = rand() % 4 + 1;
		}
	}
	move_player(move_dir, player, map);
}