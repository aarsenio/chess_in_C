#include "../../headers/chess.h"

t_piece *new_knight(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/knight1.xpm", &piece->img);
	else
		load_img("imgs/knight2.xpm", &piece->img);
	piece->type = KNIGHT;
	piece->is_move = 0;
	data()->map[x][y] = piece;
	return piece;
}
