#include "../../headers/chess.h"

static int check_move(int x, int y)
{
	if (data()->map[x][y] && data()->map[x][y]->player == data()->select->player)
		return (0);
	if (check_diagonal(x, y, data()->select->x, data()->select->y) || check_vert_hor(x, y, data()->select->x, data()->select->y))
		return (1);
	return (0);
}

t_piece *new_queen(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/queen1.xpm", &piece->img);
	else
		load_img("imgs/queen2.xpm", &piece->img);
	piece->type = QUEEN;
	piece->is_move = 0;
	piece->check_move = check_move;
	data()->map[x][y] = piece;
	return piece;
}
