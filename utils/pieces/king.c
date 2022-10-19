#include "../../headers/chess.h"

static int check_move(int x, int y)
{
	int	math_x,math_y;
	if (data()->map[x][y] && data()->map[x][y]->player == data()->select->player)
		return (0);
	math_x = x - data()->select->x;
	math_y = y - data()->select->y;
	if (math_x < 0)
		math_x *= -1;
	if (math_y < 0)
		math_y *= -1;
	if (math_x > 1 || math_y > 1)
		return (0);
	return (1);
}

t_piece *new_king(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/king1.xpm", &piece->img);
	else
		load_img("imgs/king2.xpm", &piece->img);
	piece->type = KING;
	piece->is_move = 0;
	piece->check_move = check_move;
	data()->map[x][y] = piece;
	return piece;
}