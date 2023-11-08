/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:25:10 by vdenisse          #+#    #+#             */
/*   Updated: 2023/11/08 11:37:41 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "src/gln/get_next_line.h"
# include "src/libft/header/libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define LEFT -1
# define RIGHT 1
# define UP -10
# define DOWN 10

# define PLAYER "rat"
# define EXTENSION ".xpm"
# define TEXTURE_SIZE "128x128"
# define TEXTURE_INT 128
# define TILE_HEIGHT 8
# define TILE_WIDTH 15

# define IMAGE_CREATION_ERR 521
# define EXTENTION_ERR 839
# define DIMENSION_ERR 523
# define MAP_CONTENT_ERR 1028
# define INVALID_NAME_ERR 1063
# define INVALID_OUTER_WALL 101
# define INVALID_CONTENT 307
# define INCOMPLETABLE 797
# define OPEN_ERR 1997
# define MALLOC_ERR 1423
# define GNL_ERR 2687
# define GET_TILE_ERR 1931

typedef struct s_tile
{
	char		code;
	char		*texture_path;
	void		*img;
}				t_tile;

typedef struct s_tile_set
{
	t_tile		*up;
	t_tile		*right;
	t_tile		*down;
	t_tile		*left;
}				t_tile_set;

typedef struct s_tiles
{
	t_tile		*obstacle;
	t_tile		*empty;
	t_tile		*collectible;
	t_tile_set	*player;
	t_tile		*start;
	t_tile		*end;
	t_tile		*full;
	t_tile		*flooded;
}				t_tiles;
typedef struct s_map
{
	t_tile		*tile;
	int			x;
	int			y;
}				t_map;
typedef struct s_map_seg
{
	t_map		*map_src;
	int			oob;
	int			curr_x;
	int			curr_y;
	int			to_update;
}				t_map_seg;
typedef struct s_game_info
{
	int			step_count;
	int			total_collectibles;
	int			collectibles_collected;
	t_tile		*stand_on_tile;
}				t_game_info;
typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	t_tiles		*tiles;
	t_game_info	game_info;
	int			width;
	int			height;
	int			texture_size;
	t_map		**map;
	t_map_seg	**map_seg;
	int			max_x;
	int			max_y;
}				t_data;

//cleanup.c
void			cleanup(t_data *data);
void			free_map(t_data *data, t_map **map);
void			tiles_free(t_tiles *tiles);
void			destroy_images(t_data *data, t_tiles *tiles);

//creation.c
t_tiles			*tiles_init(void);
int				create_images(t_data *data);

//event_handle.c
int				click_close(t_data **data_src);
int				key_handle(int keycode, t_data **data_src);
int				key_handle_game(int keycode, t_data **data_src);

//move_start.c
int				move_start(t_data *data, int move);

//map_cheack.c
int				map_check(int x, int y, t_data *data);

//map_flood.c
int				map_flood_check(t_map **map, int x, int y, t_tiles *tiles);

//map_parse.c
int				map_parse(t_data **data, char *map_src, t_tiles *tiles);

//map_segmenter.c
void			map_seg_free(t_map_seg **map_seg);
t_map_seg		**get_map_segment(t_data *data, int centered);

//master.c
int				master(t_data *data);
int				game_start(t_data **data_src);

//print_map_textures.c
int				update_screen(t_data **data_src);

//utils.c
int				check_extension(char *map_src);
t_tile			*get_tile(char c, t_tiles *tiles);
int				finder(t_data *data, int *y, int *x, char code);
void			print_game_info(t_data *data);

/*
void			loop(void);
void			texture_print(void);
void			print_map(t_map *map[], int	x, int y);


//game
int				smart_update_screen(t_data **data_src, int move);
int				move_invalid(t_data *data, int move);
int				map_seg_update_checker(int move, int seg_y, int seg_x);
int	map_seg_updater(t_data **data_src, int move, int seg_y,
					int seg_x);
void	map_segmenter_dynamic(t_data *data, int move, int seg_y,
					int seg_x);
void			print_map_seg(t_map_seg **map_seg, int max_y, int max_x);

//testing
void			move_test(t_data *data);
void			move_test_seg(t_data *data);
int				player_finder_seg(t_data *data, int *y, int *x);
int				move_start_no_tex(t_data *data, int move);
*/
#endif
