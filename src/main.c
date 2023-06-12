#include "../headers/header.h"

enemy_t enemy;
/**
 * main - entry point of the game
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: always success
 */
int main(int argc, char **argv)
{
	SDL_Instance instance;

	/* Initializing SDL instance */
	if (init_instance(&instance) != 0)
		return (1);
	/* Initialize game */
	init_game();
	if (argc > 1)
		make_map(argv);
	while ("game is running")
	{
		/* Clear screen */
		SDL_SetRenderDrawColor(instance.ren, 255, 255, 255, 255);
		SDL_RenderClear(instance.ren);

		/* Handle poll events */
		if (poll_events(instance) == 1)
			break;
		display(instance);
		SDL_RenderPresent(instance.ren);
	}

	/* Clean and exit */
	SDL_DestroyRenderer(instance.ren);
	SDL_DestroyWindow(instance.win);
	SDL_Quit();
	return (0);
}
/**
 * display - game window
 * @instance: given sdl instance
 *
 * Return: void
 */
void display(SDL_Instance instance)
{
	/* Perform all actions */
	ray_cast(instance);
	add_enemy(instance);
	draw_map(instance);
	display_player(instance);
	add_weapon(instance);
	draw_sprite_map(instance);
}
/**
 * init_game - Function to initialize game
 *
 * Return: void
 */
void init_game(void)
{
	player.x = 150;
	player.y = 400;
	player.w = 12;
	player.h = 12;
	player.a = PI3;
	player.dx = cos(player.a) * 5;
	player.dy = sin(player.a) * 5;
}
