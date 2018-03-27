/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** LemiPC
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lemipc.h"

bool checks(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "--help") == 0) {
		printf("%s%s%s", HELP_USAGE, HELP_PATH, HELP_TEAM_NB);
		return (false);
	} else if (ac == 3 && strcmp(av[2], "--cleanup") == 0) {
		init_components(av[1], 0, true);
		return (false);
	}
	if (ac != 3) {
		printf("%s", HELP_USAGE);
		return (false);
	}
	return (true);
}

int main(int ac, char **av)
{
	int team = 0;

	if (!checks(ac, av))
		return (84);
	team = atoi(av[2]);
	if (team <= 0) {
		printf("%s%s%s", HELP_USAGE, HELP_PATH, HELP_TEAM_NB);
		return (84);
	}
	return (init_components(av[1], team, false));
}