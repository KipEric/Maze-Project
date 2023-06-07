#include "../headers/header.h"

enemy_t enemies[num_enemy] = {
	{79.4, 84.4, 0, "images/enm.png"},
	{250.5, 100, 5, "images/enm222.png"},
	{390.5, 205, 5, "images/enm33.png"},
	{430, 384, 5, "images/enm.png"},
	{80.3, 445.7, 5, "images/enm11.png"}
};

/**
 * add_weapon - Function to design weapon
 * @ins: given sdl instance
 *
 * Return: void
 */
void add_weapon(SDL_Instance ins)
{
	SDL_Texture *texture = NULL;
	SDL_Rect gun;
	int w, h;
	SDL_Surface *surf = IMG_Load("images/gn111.png");

	if (surf)
	{
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 255, 255));
		texture = SDL_CreateTextureFromSurface(ins.ren, surf);
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		gun.w = w * gun_scale, gun.h = h * gun_scale;
		gun.x = (SCREEN_WIDTH - gun.h) / 2;
		gun.y = (SCREEN_HEIGHT - gun.h) + 20;

		if (texture)
			SDL_RenderCopy(ins.ren, texture, NULL, &gun);
		else
			printf("Unable to create texture\n");

		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
	}
	else
		printf("Unable to create a surface\n");
}

/**
 * add_enemy - Function to design an enemy
 * @ins: given instance
 *
 * Return: void
 */
void add_enemy(SDL_Instance ins)
{
	SDL_Texture *texture = NULL;
	SDL_Rect en;
	int w, h, i;
	float dx, dy, ds, sx, DPP, e_a, e_swidth, ex, e_d;

	for (i = 0; i < num_enemy; i++)
	{
		SDL_Surface *surf = IMG_Load(enemies[i].path);

		if(surf)
		{
			SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format,
						255, 255, 255));
			texture = SDL_CreateTextureFromSurface(ins.ren, surf);
			SDL_QueryTexture(texture, NULL, NULL, &w, &h);
			dx = enemies[i].x - player.x, dy = enemies[i].y - player.y;
			ds = sqrt(dx * dx + dy * dy);
			e_a = atan2(dy, dx) - player.a, e_d = cos(e_a) * ds;
			DPP = find_viewdistance(), e_swidth = map_s * DPP / e_d;
			sx = tan(e_a) * DPP;
			en.x = (SCREEN_WIDTH / 2) + sx - (e_swidth / 2);
			ex = e_d / 4, en.y = (SCREEN_HEIGHT - e_swidth) / 2.0f;
			en.w = e_swidth, en.h = e_swidth;

			if (texture && ex > 0 && ex < num_rays &&
				en.y < buff[(int)ex])
				SDL_RenderCopy(ins.ren, texture, NULL, &en);
		}
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
	}
}

/**
 * find_viewdistance - Function to find the distance of view point
 *
 * Return: view distance
 */
float find_viewdistance(void)
{
	float swdth = SCREEN_WIDTH / 2, a = FOV / 2;

	return (swdth / tan(a));
}
/**
 * draw_sprite_map - Function to draw sprite map
 * @ins: given sdl instance
 *
 * Return: void
 */
void draw_sprite_map(SDL_Instance ins)
{
	SDL_Rect rct;
	float sp_x, sp_y;
	int i;

	for (i = 0; i < num_enemy; i++)
	{
		sp_x = enemies[i].x * MAP_SCALE;
		sp_y = enemies[i].y * MAP_SCALE;
		rct.x = sp_x - 2, rct.y = sp_y -2;
		rct.w = 5, rct.h = 5;
		SDL_SetRenderDrawColor(ins.ren, 0, 255, 255, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(ins.ren, &rct);
	}
}

/**
 * sort_sprite - Function to sort sprite
 * @sprite: given sdl sprite
 * @spr_dis: distance of each sprite
 * @n: number of sprite
 *
 * Return: void
 */
void sort_sprite(int *sprite, double *spr_dis, int n)
{
	int i, j, t;
	double tmp;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (spr_dis[i] < spr_dis[j])
			{
				tmp = spr_dis[i];
				t = spr_dis[i];
				spr_dis[i] = spr_dis[j];
				sprite[i] = sprite[j];
				spr_dis[j] = tmp;
				sprite[j] = t;
			}
		}
	}
}
