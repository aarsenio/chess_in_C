#include "headers/chess.h"


t_data	*data()
{
	static t_data	data;

	return (&data);
}

void	init_pieces()
{
	// white pieces
	new_rook(PLAYER_1, 0, 7);
	new_knight(PLAYER_1, 1, 7);
	new_bishop(PLAYER_1, 2, 7);
	new_queen(PLAYER_1, 3, 7);
	new_king(PLAYER_1, 4, 7);
	new_bishop(PLAYER_1, 5, 7);
	new_knight(PLAYER_1, 6, 7);
	new_rook(PLAYER_1, 7, 7);
	new_pawn(PLAYER_1, 0, 6);
	new_pawn(PLAYER_1, 1, 6);
	new_pawn(PLAYER_1, 2, 6);
	new_pawn(PLAYER_1, 3, 6);
	new_pawn(PLAYER_1, 4, 6);
	new_pawn(PLAYER_1, 5, 6);
	new_pawn(PLAYER_1, 6, 6);
	new_pawn(PLAYER_1, 7, 6);
	// black pieces
	new_rook(PLAYER_2, 0, 0);
	new_knight(PLAYER_2, 1, 0);
	new_bishop(PLAYER_2, 2, 0);
	new_queen(PLAYER_2, 3, 0);
	new_king(PLAYER_2, 4, 0);
	new_bishop(PLAYER_2, 5, 0);
	new_knight(PLAYER_2, 6, 0);
	new_rook(PLAYER_2, 7, 0);
	new_pawn(PLAYER_2, 0, 1);
	new_pawn(PLAYER_2, 1, 1);
	new_pawn(PLAYER_2, 2, 1);
	new_pawn(PLAYER_2, 3, 1);
	new_pawn(PLAYER_2, 4, 1);
	new_pawn(PLAYER_2, 5, 1);
	new_pawn(PLAYER_2, 6, 1);
	new_pawn(PLAYER_2, 7, 1);
}

int	main()
{
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, 800, 800, "Chess");
	load_img( "imgs/board.xpm", &data()->board);
	load_img( "imgs/select.xpm", &data()->select_img);
	new_canva();
	init_pieces();
	board_render();
	mlx_key_hook(data()->win, key, data);
	mlx_hook(data()->win, 04, (1L << 2), key, data);
	mlx_hook(data()->win, 17, (1L << 2), exit_game, data);
	mlx_mouse_hook(data()->win, mouse, data);
	mlx_loop(data()->mlx);
}
