/*
** EPITECH PROJECT, 2018
** LemIPC
** File description:
** Player AI
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

enum direction find_closest_attacking_ally(player_t *player, int **map)
{
	int distance_x = 0;
	int distance_y = 0;
	enum direction move_dir = UNDEFINED;

	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++) {
			if (map[x][y] != player->team || map[x][y] == 0)
				continue;
			if (x == player->posx && y == player->posy)
				continue;
			if (!is_next_to_enemy(x, y, player->team, map))
				continue;
			printf("Diff posx: %d posy: %d\n", absolute(x - player->posx), absolute(y - player->posy));
			printf("Check distance x: %d\n", (absolute(distance_x) == 0) ? MAP_WIDTH : absolute(distance_x));
			printf("Check distance y: %d\n", (absolute(distance_y) == 0) ? MAP_HEIGHT : absolute(distance_y));
			printf("Check %d\n", absolute(x - player->posx) < (absolute(distance_x) == 0) ? MAP_WIDTH : absolute(distance_x));
			if (absolute(x - player->posx) < (absolute(distance_x) == 0) ? MAP_WIDTH : absolute(distance_x)) {
				printf("this is a good thing?\n");
				distance_x = x - player->posx;
				printf("OMG %d\n", distance_x);
			}
			if (absolute(y - player->posy) < (absolute(distance_y) == 0) ? MAP_HEIGHT : absolute(distance_y)) {
				printf("this is a good thing?\n");
				distance_y = y - player->posy;
				printf("OMG %d\n", distance_y);
			}
		}
	}
	printf("Distance_x: %d - Distance_y: %d\n", absolute(distance_x), absolute(distance_y));
	if (absolute(distance_x) < absolute(distance_y)) {
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
	return (move_dir);
}

enum direction find_closest_enemy(player_t *player, int **map)
{
	int distance_x = 0;
	int distance_y = 0;
	enum direction move_dir = UNDEFINED;

	for (int x = 0; x < MAP_WIDTH; x++) {
		for (int y = 0; y < MAP_HEIGHT; y++) {
			if (map[x][y] == player->team || map[x][y] == 0)
				continue;
			printf("Found enemy\n");
			printf("Diff posx: %d posy: %d\n", absolute(x - player->posx), absolute(y - player->posy));
			printf("Check distance x: %d\n", (absolute(distance_x) == 0) ? MAP_WIDTH : absolute(distance_x));
			printf("Check distance y: %d\n", (absolute(distance_y) == 0) ? MAP_HEIGHT : absolute(distance_y));
			printf("Check %d\n", absolute(x - player->posx) < (absolute(distance_x) == 0) ? MAP_WIDTH : absolute(distance_x));
			if (absolute(x - player->posx) < (absolute(distance_x) == 0) ? MAP_WIDTH : absolute(distance_x)) {
				printf("this is a good thing?\n");
				distance_x = x - player->posx;
				printf("OMG %d\n", distance_x);
			}
			if (absolute(y - player->posy) < (absolute(distance_y) == 0) ? MAP_HEIGHT : absolute(distance_y)) {
				printf("this is a good thing?\n");
				distance_y = y - player->posy;
				printf("OMG %d\n", distance_y);
			}
		}
	}
	printf("Distance_x: %d - Distance_y: %d\n", absolute(distance_x), absolute(distance_y));
	if (absolute(distance_x) < absolute(distance_y)) {
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
	return (move_dir);
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
	printf("Move direction: %d\n", move_dir);
	move_player(move_dir, player, map);
}