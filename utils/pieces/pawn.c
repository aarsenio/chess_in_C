#include "../../headers/chess.h"

static int check_move(int x, int y)
{
	if (x == data()->select->x && data()->map[x][y])
		return (0);
	if (data()->map[x][y] && data()->map[x][y]->player != data()->select->player && ((x - 1 == data()->select->x && y + 1 ==data()->select->y) || (x + 1 == data()->select->x && y + 1 ==data()->select->y)))
		return (1);
	if (data()->select->player == PLAYER_1)
	{
		if (y >= data()->select->y || x != data()->select->x)
			return (0);
		if (data()->select->is_move == 0)
			if (y + 2 < data()->select->y)
				return (0);
		if (data()->select->is_move == 1)
			if (y + 1 < data()->select->y)
				return (0);
	}
	else
	{
		if (x == data()->select->x && data()->map[x][y])
			return (0);
		if (data()->map[x][y] && data()->map[x][y]->player != data()->select->player && ((x - 1 == data()->select->x && y - 1 ==data()->select->y) || (x + 1 == data()->select->x && y - 1 ==data()->select->y)))
			return (1);
		if (y <= data()->select->y || x != data()->select->x)
			return (0);
		if (data()->select->is_move == 0)
			if (y - 2 > data()->select->y)
				return (0);
		if (data()->select->is_move == 1)
			if (y - 1 > data()->select->y)
				return (0);
	}
	return (1);
}

t_piece *new_pawn(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/pawn1.xpm", &piece->img);
	else
		load_img("imgs/pawn2.xpm", &piece->img);
	piece->type = PAWN;
	piece->is_move = 0;
	piece->check_move = check_move;
	data()->map[x][y] = piece;
	return piece;
}
