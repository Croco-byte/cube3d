/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:58:59 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 17:05:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	create_bmp_image(t_frame *game)
{
	game->bmp.img =
	mlx_new_image(game->mlx, game->screenWidth2, game->screenHeight2);
	game->bmp.addr = mlx_get_data_addr(game->bmp.img, &game->bmp.bits_per_pixel,
							&game->bmp.line_length, &game->bmp.endian);
	handle_movements(game);
	do_walls(game);
	do_sprites(game);
	put_buffer_in_image(game, &game->bmp);
}

static void	file_header(t_frame *game, int fd)
{
	int	file_size;
	int	pixel_data_offset;

	pixel_data_offset = 54;
	file_size = pixel_data_offset + game->screenWidth2 *
		game->screenHeight2 * 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &pixel_data_offset, 4);
}

static void	image_header(t_frame *game, int fd)
{
	int	header_size;
	int	plane;
	int	image_size;

	header_size = 40;
	plane = 1;
	image_size = game->screenWidth2 * game->screenHeight2;
	write(fd, &header_size, 4);
	write(fd, &game->screenWidth2, 4);
	write(fd, &game->screenHeight2, 4);
	write(fd, &plane, 2);
	write(fd, &game->bmp.bits_per_pixel, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &image_size, 4);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 16);
}

static void	fill_bitmap(t_frame *game, int fd)
{
	int	x;
	int y;
	int	r;
	int	g;
	int	b;

	y = game->screenHeight2;
	while (--y >= 0)
	{
		x = 0;
		while (x < game->screenWidth2)
		{
			r = game->bmp.addr[y * game->bmp.line_length + x *
			game->bmp.bits_per_pixel / 8];
			g = game->bmp.addr[y * game->bmp.line_length + x *
			game->bmp.bits_per_pixel / 8 + 1];
			b = game->bmp.addr[y * game->bmp.line_length + x *
			game->bmp.bits_per_pixel / 8 + 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
			x++;
		}
	}
}

void		create_bitmap(t_frame *game)
{
	int	fd;

	if ((fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) < 0)
	{
		ft_printf("Can't open output file for screenshot. Exiting...\n");
		clean_exit(game);
	}
	create_bmp_image(game);
	file_header(game, fd);
	image_header(game, fd);
	fill_bitmap(game, fd);
	mlx_destroy_image(game->mlx, game->bmp.img);
	close(fd);
	clean_exit(game);
}
