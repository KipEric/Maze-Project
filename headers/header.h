#ifndef HEADER_H
#define HEADER_H

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 600
#define gun_scale 0.35
#define map_x 8
#define map_y 8
#define map_s 64
#define PI 3.14159265
#define PI2 (0.5 * PI)
#define PI3 (1.5 * PI)
#define DR 0.0174533
#define MAP_SCALE 0.25
#define num_enemy 5
#define FOV (PI / 3)
#define RAD_DEG 57.296
#define num_rays 60

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

typedef struct SDL_Instance
{
	SDL_Window *win;
	SDL_Renderer *ren;
} SDL_Instance;

typedef struct btn_keys
{
	int w, a, d, s, e, x;
} btn_keys;

typedef struct player_s
{
	float x, y, w, h, a, dx, dy;
} player_t;

extern player_t player;

typedef struct enemy_s
{
	float x, y, z;
	char *path;
} enemy_t;

extern enemy_t enemy;
extern float buff[num_rays];

void init_game(void);
void display(SDL_Instance instance);
int poll_events(SDL_Instance instance);
void handle_key_down(SDL_Instance instance);
void key_up(SDL_Event ev);
void key_down(SDL_Event ev);
void handle_door(void);
int init_instance(SDL_Instance *in);
float FixAng(float a);
void display_player(SDL_Instance instance);
void draw_map(SDL_Instance ins);
void draw_scene(SDL_Instance ins, int n, float h, float ray_a, float shade,
		float rx, float ry, int m_txr);
void draw_floor(SDL_Instance ins, float ln_off, int n, float line);
void draw_roof(SDL_Instance ins, float ln_off, int n, float line);
void ray_cast(SDL_Instance ins);
int hit_wall(float rx, float ry);
void horizontal_collision(float ray_a, float *d, float *hx, float *hy, int *h);
void vertical_collision(float ray_a, float *vd, float *vx, float *vy, int *v);
float find_distance(float ax, float ay, float bx, float by);
void add_weapon(SDL_Instance ins);
void add_enemy(SDL_Instance ins);
float find_viewdistance(void);
void draw_sprite_map(SDL_Instance ins);
void sort_sprite(int *sprite, double *spr_dis, int n);
float get_texture(int idx);
void setmap_value(int mx, int my, int val);
int getmap_value(int x, int y, int mp);
void free_numbers(int **numbers);
void make_map(char **argv);
int _atoi(char *s);
char *_strdup(char *str);
int _length(char *str);
int **get_altitude(char **argv);
char **str_split(char *str, char *del);
void free_grid(SDL_Point ***grid);
void free_tokens(char **tokens);
void free_cols(char ***cols);
void free_numbers(int **numbers);

#endif /*HEADER_H*/
