/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** LemiPC
*/

#include <stdio.h>
#include <string.h>
#include "lemipc.h"

int main(int ac, char **av)
{
	if (ac == 2 && strcmp(av[1], "--help") == 0) {
		printf("%s%s%s", HELP_USAGE, HELP_PATH, HELP_TEAM_NB);
		return (0);
	}
	if (ac != 3) {
		printf("%s", HELP_USAGE);
		return (84);
	}
	init_components(av[1], av[2]);
}