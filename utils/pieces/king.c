#include "../../headers/chess.h"

t_piece *new_king(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/king1.xpm", &piece->img);
	else
		load_img("imgs/king2.xpm", &piece->img);
	piece->type = KING;
	piece->is_move = 0;
	data()->map[x][y] = piece;
	return piece;
}