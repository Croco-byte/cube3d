/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:55:15 by user42            #+#    #+#             */
/*   Updated: 2021/01/03 14:10:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_map_infos(t_frame *game)
{
	int	i;

	i = 0;
	if (game->worldmap2 == 0)
	{
		ft_printf("No map was provided in file. Exiting...\n");
		clean_exit(game);
	}
	while (game->worldmap2[i])
		i++;
	game->nboflines = i;
}

void	treat_options(t_frame *game, char *line, int i)
{
	if (line[i] == 'R')
		get_resolution(game, line, i);
	if (line[i] == 'N' && line[i + 1] == 'O')
		get_no_tex(game, line, i);
	if (line[i] == 'S' && line[i + 1] == 'O')
		get_so_tex(game, line, i);
	if (line[i] == 'W' && line[i + 1] == 'E')
		get_we_tex(game, line, i);
	if (line[i] == 'E' && line[i + 1] == 'A')
		get_ea_tex(game, line, i);
	if (line[i] == 'S' && line[i + 1] != 'O' && line[i + 1] != '2'
		&& line[i + 1] != '3' && line[i + 1] != '4')
		get_s_tex(game, line, i);
	if (line[i] == 'S' && line[i + 1] == '2')
		get_s2_tex(game, line, i);
	if (line[i] == 'S' && line[i + 1] == '3')
		get_s3_tex(game, line, i);
	if (line[i] == 'S' && line[i + 1] == '4')
		get_s4_tex(game, line, i);
	if (line[i] == 'F')
		game->floor = parse_color(line, i);
	if (line[i] == 'C')
		game->ceiling = parse_color(line, i);
}

void	parse_options_and_map(t_frame *game, int fd)
{
	int		i;
	int		reader;
	char	*line;
	char	*result;
	int		parsing_worldmap;

	result = 0;
	parsing_worldmap = 0;
	reader = 1;
	while (reader > 0)
	{
		reader = get_next_line(fd, &line);
		i = 0;
		i += pass_spaces(line, i);
		if (is_map_digit(line[i]))
			parsing_worldmap = 1;
		if (reader != -1 && line[i] && !parsing_worldmap)
			treat_options(game, line, i);
		if (reader != -1 && line[i] && parsing_worldmap)
			result = ft_mapjoin(result, line);
		free(line);
	}
	game->worldmap2 = ft_split(result, '\n');
	free(result);
}

void	check_paths(t_frame *game)
{
	if (game->paths.nopath == 0 || game->paths.sopath == 0
		|| game->paths.wepath == 0 || game->paths.eapath == 0
		|| game->paths.spath == 0)
	{
		ft_printf("Missing a mandatory path. Exiting...\n");
		clean_exit(game);
	}
	if (game->paths.s2path == 0)
		game->paths.s2path = ft_strdup("./textures/guard.xpm");
	if (game->paths.s3path == 0)
		game->paths.s3path = ft_strdup("./textures/cage.xpm");
	if (game->paths.s4path == 0)
		game->paths.s4path = ft_strdup("./textures/spear.xpm");
}

void	parse_stuff(t_frame *game, int argc, char **argv)
{
	int		fd;

	fd = open_map(game, argc, argv);
	parse_options_and_map(game, fd);
	if (game->screenheight <= 0 || game->screenwidth <= 0)
	{
		ft_printf("Resolution can't be 0 or inferior. Exiting...\n");
		clean_exit(game);
	}
	set_map_infos(game);
	check_map_content(game);
	check_left(game);
	check_right(game);
	check_paths(game);
}
