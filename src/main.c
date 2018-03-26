/*
** EPITECH PROJECT, 2018
** LemiPC
** File description:
** LemiPC
*/

#include <stdio.h>
#include "lemipc.h"

int main(int ac, char **av)
{
	if (ac == 1 && strcmp(av[1], "--help") == 0) {
		printf("%s%s%s", HELP_USAGE, HELP_PATH, HELP_TEAM_NB);
		return (0);
	}
	if (ac != 3) {
		printf("%s\n", HELP_USAGE);
		return (84);
	}
	// Start
}