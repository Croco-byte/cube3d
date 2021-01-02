/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:46:14 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 16:37:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../libft/ft_printf/printf.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>

# define ESC_KEY 65307
# define Z_KEY 122
# define Q_KEY 113
# define D_KEY 100
# define S_KEY 115
# define A_KEY 97
# define E_KEY 101
# define ARR_LEFT 65361
# define ARR_RIGHT 65363

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
	int			moveForward;
	int			moveBack;
	int			moveLeft;
	int			moveRight;
	int			rotateLeft;
	int			rotateRight;
}				t_player;

typedef struct	s_textures
{
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	int			*northTex;
	int			*southTex;
	int			*westTex;
	int			*eastTex;
	int			texWidth;
	int			texHeight;
}				t_textures;

typedef struct	s_spriteLoc
{
	double		x;
	double		y;
	int			sprTex;
}				t_spriteLoc;

typedef struct	s_sprites
{
	t_img		sprite1;
	t_img		sprite2;
	t_img		sprite3;
	t_img		sprite4;
	int			*sprite1Tex;
	int			*sprite2Tex;
	int			*sprite3Tex;
	int			*sprite4Tex;
	int			texWidth;
	int			texHeight;
	int			numSprites;
	int			*spriteOrder;
	double		*spriteDist;
	t_spriteLoc	*spr;
}				t_sprites;

typedef struct	s_paths
{
	char		*nopath;
	char		*sopath;
	char		*wepath;
	char		*eapath;
	char		*spath;
	char		*s2path;
	char		*s3path;
	char		*s4path;
}				t_paths;

typedef struct	s_frame
{
	void		*mlx;
	void		*win;
	int			screenWidth2;
	int			screenHeight2;
	int			ceiling;
	int			floor;
	int			**buffer;
	double		*ZBuffer;
	char		**worldmap2;
	int			nboflines;
	t_player	player;
	t_textures	textures;
	t_sprites	sprites;
	t_paths		paths;
	t_img		bmp;
}				t_frame;

typedef struct	s_raycast
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		wallX;
	int			texX;
	int			texY;
	double		step;
	double		texPos;
	int			color;
}				t_raycast;

typedef struct	s_sprutils
{
	double		spriteX;
	double		spriteY;
	double		invDet;
	double		transformX;
	double		transformY;
	int			spriteScreenX;
	int			spriteHeight;
	int			spriteWidth;
	int			drawStartY;
	int			drawEndY;
	int			drawStartX;
	int			drawEndX;
	int			texX;
	int			texY;
	int			d;
	int			color;
}				t_sprutils;

void			init_game(t_frame *game);
void			init_player(t_frame *game);
void			init_worldMap(t_frame *game);
void			allocate_buffers(t_frame *game);
void			init_buffer(t_frame *game);
void			load(t_frame *game, t_textures *textures, t_sprites *sprites);
void			init_sprites(t_frame *game);

void			do_walls(t_frame *game);
void			init_raycast(t_frame *game, t_raycast *raycaster, int x);
void			dda_preparations(t_frame *game, t_raycast *raycaster);
void			dda_perform(t_frame *game, t_raycast *raycaster);
void			calc_draw_coordinates(t_frame *game, t_raycast *raycaster);
void			calc_texture_coordinates(t_frame *game, t_raycast *raycaster);
void			draw_stripe_in_buffer(t_frame *game, t_raycast *raycaster, int x);
void			put_buffer_in_image(t_frame *game, t_img *render);

void			do_sprites(t_frame *game);
void			init_sprarray(t_frame *game);
void			init_sprutils(t_frame *game, t_sprutils *sprutils, int i);
void			spr_coordinates(t_frame *game, t_sprutils *sprutils);
void			spr_draw(t_frame *game, t_sprutils *sprutils, int i);
void			draw_vert_spr(t_frame *game, t_sprutils *sprutils, int i, int stripe);
void			choose_sprite(t_frame *game, t_sprutils *sprutils, int i);

int				rgb_to_int(int t, int r, int g, int b);
int				trgb_to_values(int trgb, char c);

void			draw_in_image(t_img *img, int x, int y, int color);
void			sort_sprites(double *spriteDist, int *spriteOrder, int size);

void			free_game_buffer(t_frame *game);
void			free_game_worldmap(t_frame *game);
void			free_textures_images(t_frame *game);
void			free_sprites_images(t_frame *game);
int				clean_exit(t_frame *var);

void			event_handler(t_frame *var);
int				key_press(int keycode, t_frame *var);
int				key_release(int keycode, t_frame *game);
void			handle_movements(t_frame *game);

void			move_forward(t_frame *game);
void			move_back(t_frame *game);
void			move_left(t_frame *game);
void			move_right(t_frame *game);
void			rotate_left(t_frame *game);
void			rotate_right(t_frame *game);

int				get_next_line(int fd, char **line);
int				has_return(char *str);
char			*line_from_save(char *save);
char			*update_save(char *save, int *last_line);
char			*ft_gnljoin(char const *s1, char const *s2);
int				malloc_fails(char **line, char *save, int *last_line);
int				is_last_line(char *save, int *last_line, int i);

int				pass_spaces(char *line, int i);
char			*ft_mapjoin(char const *s1, char const *s2);
int				open_map(t_frame *game, int argc, char **argv);
void			parse_stuff(t_frame *game, int argc, char **argv);
void			check_map_content(t_frame *game);
void			check_left(t_frame *game);
void			check_right(t_frame *game);

void			get_no_tex(t_frame *game, char *line, int i);
void			get_so_tex(t_frame *game, char *line, int i);
void			get_we_tex(t_frame *game, char *line, int i);
void			get_ea_tex(t_frame *game, char *line, int i);
void			get_s_tex(t_frame *game, char *line, int i);
void			get_s2_tex(t_frame *game, char *line, int i);
void			get_s3_tex(t_frame *game, char *line, int i);
void			get_s4_tex(t_frame *game, char *line, int i);
void			get_resolution(t_frame *game, char *line, int i);
int				parse_color(char *line, int i);
int				is_map_digit(char c);
int				is_map_char(char c);

void			create_bitmap(t_frame *game);

#endif


/* TODO :
+ revoir clean_exit pour bien tout libérer dans tous les cas
+ revoir les key bindings
+ norme
+ revoir les conditions de création de l'image bitmap */
