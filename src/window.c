#include "../headers/header.h"

/**
 * init_instance - initialize all instance
 * @in: given instance
 *
 * Return: 0 on success or 1 on fail
 */
int init_instance(SDL_Instance *in)
{
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	/* Create SDL window */
	in->win = SDL_CreateWindow("Eric Maze", 0, 0,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
	if (in->win == NULL)
	{
		fprintf(stderr, "Unable to create SDL_Window: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	/* Create SDL renderer */
	in->ren = SDL_CreateRenderer(in->win, -1, SDL_RENDERER_ACCELERATED
			| SDL_RENDERER_PRESENTVSYNC);

	if (in->ren == NULL)
	{
		fprintf(stderr, "Unable to create Renderer: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		fprintf(stderr, "Failed to initialize image: %s\n", SDL_GetError());
		return (1);
	}
	return (0);
}

/**
 * FixAng - reset the angle if it is above the range
 * @a: given angle
 *
 * Return: converted angle
 */
float FixAng(float a)
{
	if (a > 2 * PI)
		a -= 2 * PI;
	if (a < 0)
		a += 2 * PI;
	return (a);
}
