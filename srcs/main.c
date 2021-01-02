/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:42:52 by user42            #+#    #+#             */
/*   Updated: 2021/01/02 16:53:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main_loop(t_frame *game)
{
	t_img render;

	render.img =
	mlx_new_image(game->mlx, game->screenWidth2, game->screenHeight2);
	render.addr = mlx_get_data_addr(render.img, &render.bits_per_pixel,
							&render.line_length, &render.endian);
	handle_movements(game);
	do_walls(game);
	do_sprites(game);
	put_buffer_in_image(game, &render);
	mlx_put_image_to_window(game->mlx, game->win, render.img, 0, 0);
	init_buffer(game);
	mlx_destroy_image(game->mlx, render.img);
	return (0);
}

int		main(int argc, char **argv)
{
	t_frame	game;

	game.mlx = mlx_init();
	init_game(&game);
	parse_stuff(&game, argc, argv);
	init_player(&game);
	if (argc == 2 || (argc > 2 &&
		ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0))
		game.win = mlx_new_window(game.mlx, game.screenWidth2,
										game.screenHeight2, "Raycasting");
	allocate_buffers(&game);
	init_buffer(&game);
	load(&game, &game.textures, &game.sprites);
	init_sprites(&game);
	if (argc > 2 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
		create_bitmap(&game);
	if (argc == 2 || (argc > 2 &&
		ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0))
	{
		event_handler(&game);
		mlx_loop_hook(game.mlx, &main_loop, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
