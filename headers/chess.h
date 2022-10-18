#ifndef CHESS_H
# define CHESS_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <mlx.h>

# define COLOR_TRANSPARENT 0xd411aa

enum s_players
{
	PLAYER_1 = 1,
	PLAYER_2
};

typedef enum s_types
{
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING
} t_types;

typedef struct	s_data_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data_img;

typedef struct s_piece
{
	t_types			type;
	t_data_img		img;
	int				(*check_move)(int x, int y);
	void			(*move)(int	x, int y);
	int				x;
	int				y;
	int				is_move;
	int 			player;
}	t_piece;

typedef struct s_data
{
	t_data_img		floor[2];
	void			*mlx;
	void			*win;
	t_data_img		canva;
	t_piece			*select;
	t_piece			*map[8][8];
}	t_data;



void		board_render(int x, int y, int counter);
void		print_error(char *str, int error);
void 		new_canva();
void 		print_img(t_data_img	data, int x1, int y1);
int			exit_game();
int			key(int keycode, void *param);
int			mouse(int event, void *param);
void  		load_img(char *file, t_data_img *img);
t_data		*data();
t_piece 	*new_piece(int player, int x, int y);
t_piece 	*new_king(int player, int x, int y);
t_piece 	*new_queen(int player, int x, int y);
t_piece 	*new_bishop(int player, int x, int y);
t_piece 	*new_knight(int player, int x, int y);
t_piece 	*new_rook(int player, int x, int y);
t_piece 	*new_pawn(int player, int x, int y);
void		free_piece(t_piece *piece);

#endif