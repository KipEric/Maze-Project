#include "../headers/header.h"

int map[map_y][map_x] = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
	};

int map_floor[map_y][map_x] = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
	};

/**
 * getmap_value - find the value of the given coordinate
 * @x: x-coordinate
 * @y: y-coordinate
 * @mp: required map type
 *
 * Return: value at x, y
 */
int getmap_value(int x, int y, int mp)
{
	if (mp == 1)
		return (map_floor[y][x]);
	else
		return(map[y][x]);
}

/**
 * setmap_value - set the value of map at a given coordinate
 * @x: x-coordinate
 * @y: y-coordinate
 * @val: value to set
 *
 * Return: void
 */
void setmap_value(int x, int y, int val)
{
	map[y][x] = val;
}
/**
 * make_map - Function to design the map
 * @argv: argument vector
 *
 * Return: void
 */
void make_map(char **argv)
{
	int i, j;
	int **file_map;

	file_map = get_altitude(argv);
	for (i = 0; i < map_x; i++)
	{
		for (j = 0; j < map_y; j++)
			map[i][j] = file_map[i][j];
	}
	free_numbers(file_map);
}
