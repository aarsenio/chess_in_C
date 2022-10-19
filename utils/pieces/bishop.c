#include "../../headers/chess.h"

int	check_diagonal(int x, int y, int x1, int y1)
{
	int i;
	int dif_x;
	int dif_y;

	i = 0;
	dif_x = 1;
	if (x > x1)
		dif_x = -1;
	dif_y = 1;
	if (y > y1)
		dif_y = -1;
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

static int	check_move(int x, int y)
{
	int math_x, math_y;
	if (data()->map[x][y] && data()->map[x][y]->player == data()->select->player)
		return (0);
	math_x = data()->select->x - x;
	if (math_x < 0)
		math_x *= -1;
	math_y = data()->select->y - y;
	if (math_y < 0)
		math_y *= -1;
	if (math_x  != math_y)
		return (0);
	if (check_diagonal(data()->select->x, data()->select->y, x, y))
		return (!data()->map[x][y] || data()->map[x][y]->type != KING);
	return (0);
}

t_piece *new_bishop(int player, int x, int y)
{
	t_piece *piece = new_piece(player, x, y);
	if (player == 1)
		load_img("imgs/bishop1.xpm", &piece->img);
	else
		load_img("imgs/bishop2.xpm", &piece->img);	
	piece->type = BISHOP;
	piece->is_move = 0;
	piece->check_move = check_move;
	data()->map[x][y] = piece;
	return piece;
}
