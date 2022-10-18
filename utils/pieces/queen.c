#include "../../headers/chess.h"

t_piece *new_queen(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/queen1.xpm", &piece->img);
	else
		load_img("imgs/queen2.xpm", &piece->img);
	piece->type = QUEEN;
	piece->is_move = 0;
	data()->map[x][y] = piece;
	return piece;
}
