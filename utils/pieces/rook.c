#include "../../headers/chess.h"

t_piece *new_rook(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/rook1.xpm", &piece->img);
	else
		load_img("imgs/rook2.xpm", &piece->img);
	piece->type = ROOK;
	piece->is_move = 0;
	data()->map[x][y] = piece;
	return piece;
}
