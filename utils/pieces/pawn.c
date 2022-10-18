#include "../../headers/chess.h"

static int check_move(int x, int y)
{
	if (data()->select->player == PLAYER_1)
	{
		if (y >= data()->select->y || x != data()->select->x)
			return (0);
	}
	else
	{
		if (y <= data()->select->y || x != data()->select->x)
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
