#include "../headers/header.h"

/**
 * free_grid - free allocated memory of grid
 * @grid: given sdl grid
 *
 * Return: void
 */
void free_grid(SDL_Point ***grid)
{
	int i, j;

	for (j = 0; j < map_x; j++)
		free(grid[0][j]);
	free(grid[0]);
	for (i = 0; i < map_y; i++)
		free(grid[1][i]);
	free(grid[1]);
	free(grid);
}
/**
 * free_tokens - free memmory allocated to tokens
 * @tokens: given sdl tokens
 *
 * Return: void
 */
void free_tokens(char **tokens)
{
	char **tmp = tokens;

	if (tokens)
	{
		while(*tokens)
			free(*tokens++);
		free(tmp);
	}
}
/**
 * free_cols - free allocated memory for colums
 * @cols: given sdl columns
 *
 * Return: void
 */
void free_cols(char ***cols)
{
	int i, j;

	for (i = 0; i < map_x; i++)
	{
		for (j = 0; j < map_y; j++)
			free(cols[i][j]);
		free(cols[i]);
	}
	free(cols);
}
/**
 * free_numbers -function to free memory alloctated for numbers
 * @numbers: given sdl numbers
 *
 * Return: void
 */
void free_numbers(int **numbers)
{
	int i;

	for (i = 0; i < map_x; i++)
		free(numbers[i]);
	free(numbers);
}
