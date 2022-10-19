#include "../../headers/chess.h"

static int	check_vert_hor(int x, int y, int x1, int y1)
{
	int i;
	int dif_x;
	int dif_y;

	i = 0;
	dif_x = 1;
	dif_y = 1;
	if (x == x1)
	{
		dif_x = 0;
		if (y > y1)
			dif_y = -1;
	}
	if (y == y1)
	{
		dif_y = 0;
		if (x > x1)
			dif_x = -1;
	}
	while (i < 8)
	{
		x += dif_x;
		y += dif_y;
		if (x == x1 && y == y1)
			return (1);
		if (data()->map[x][y])
			return (0);
		i++;
	}
	return (0);
}

static int check_move(int x, int y)
{
	if (data()->map[x][y] && data()->map[x][y]->player == data()->select->player)
		return (0);
	if (x != data()->select->x && y != data()->select->y)
		return (0);
	return (check_vert_hor(x, y, data()->select->x, data()->select->y));
}

t_piece *new_rook(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/rook1.xpm", &piece->img);
	else
		load_img("imgs/rook2.xpm", &piece->img);
	piece->type = ROOK;
	piece->is_move = 0;
	piece->check_move = check_move;
	data()->map[x][y] = piece;
	return piece;
}
