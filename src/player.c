#include "../headers/header.h"

player_t player;
/**
 * display_player - Function to display the player
 * @instance: given sdl2 instance
 *
 * Return: void
 */
void display_player(SDL_Instance instance)
{
	SDL_Rect rect;
	float x0, y0, x1, y1;

	rect.x = player.x * MAP_SCALE, rect.y = player.y * MAP_SCALE;
	rect.w = player.w * MAP_SCALE, rect.h = player.w * MAP_SCALE;

	SDL_SetRenderDrawColor(instance.ren, 255, 255, 0, 0);
	SDL_RenderFillRect(instance.ren, &rect);

	x0 = player.x * MAP_SCALE;
	y0 = player.y * MAP_SCALE;
	x1 = (player.x + player.dx * 20) * MAP_SCALE;
	y1 = (player.x + player.dy * 20) * MAP_SCALE;
	SDL_RenderDrawLine(instance.ren, x0, y0, x1, y1);
}

/**
 * draw_map - Function to draw map
 * @ins: given SDL instance
 *
 * Return: void
 */
void draw_map(SDL_Instance ins)
{
	int x, y;
	SDL_Rect rect;

	for (x = 0; x < map_x; x++)
	{
		for (y = 0; y < map_y; y++)
		{
			if (getmap_value(y, x, 0) > 0)
				SDL_SetRenderDrawColor(ins.ren, 255, 255, 255, 0);
			else
				SDL_SetRenderDrawColor(ins.ren, 0, 0, 0, 0);

			rect.x = (y * map_s * MAP_SCALE) + 1;
			rect.y = (x * map_s * MAP_SCALE) + 1;
			rect.w = (map_s * MAP_SCALE) - 1;
			rect.h = (map_s * MAP_SCALE) - 1;
			SDL_RenderFillRect(ins.ren, &rect);
		}
	}
}
/**
 * draw_scen - Function to draw the scen
 * @ins: given sdl instance
 * @n: ray number
 * @h: height
 * @ray_a: angle of the ray
 * @shd: shading value
 * @rx: x-coordinate of the ray
 * @ry: y-coordinate of the ray
 * @m_txr: map texture value
 *
 * Return: void
 */

void draw_scene(SDL_Instance ins, int n, float h, float ray_a, float shd,
		float rx, float ry, int m_txr)
{
	float line, a = FixAng(player.a - ray_a), of, tx_y = 0, tx_x, tx_s;
	int j, i, s = (int)SCREEN_WIDTH / 60;

	h = h * cos(a);
	line = (map_s * 420) / h;
	tx_s = 32.0 / (float)line;
	of = 280 - (line / 2);

	if (line > 420)
		line = 420, tx_y = (line - 420) / 2.0;
	tx_y = (tx_y * tx_s) + (m_txr * 32);

	if (shd == 1)
	{
		tx_x = (int) (rx / 2.0) % 32;
		if (ray_a > PI)
			tx_x = 31 - tx_x;
	}
	else
	{
		tx_x = (int) (ry / 2.0) % 32;
		if (ray_a > PI2 && ray_a < PI3)
			tx_x = 31 - tx_x;
	}
	for (i = 0; i < line; i++)
	{
		//	wall color
		SDL_SetRenderDrawColor(ins.ren, 255, 255, 255, 0);
		for (j = n * s; j < (n * s) + s; j++)
			SDL_RenderDrawPoint(ins.ren, j, i + of);
		tx_y += tx_s;
	}
	draw_floor(ins, of, n, line);
}
/**
 * draw_floor - Fundtion to designn floor
 * @ln_off: line offset
 * @line: vertical line
 * @ra: ray angle
 * @n: index of each ray
 * @ins: given instance
 *
 * Return: void
 */
void draw_floor(SDL_Instance ins, float ln_off, int n, float line)
{
	int i, j, s = (int)SCREEN_WIDTH / 60;
	Uint8 r = 128, g = 0, b = 0;

	for (i = ln_off + line; i < SCREEN_HEIGHT; i++)
	{
		SDL_SetRenderDrawColor(ins.ren, r, g, b, 0);
		
		for (j = n * s; j < (n * s) + s; j++)
			SDL_RenderDrawPoint(ins.ren, j, i);
	}
}
/**
 * draw_roof - function to design roof
 * @ln_off: line offset
 * @line: vertical line
 * @ra: ray angle
 * @ins: given sdl instance
 * @n: index of each ray
 *
 * Return: void
 */
void draw_roof(SDL_Instance ins, float ln_off, int n, float line)
{
	int i, j;

	for (i = ln_off + line; i < 500; i++)
	{
		SDL_SetRenderDrawColor(ins.ren, 30, 144, 255, 0);

		for (j = n * 8; j < (n * 8) + 8; j++)
			SDL_RenderDrawPoint(ins.ren, j + 530, 500 - i);
	}
}
