#include "../../headers/chess.h"

static int	check_move(int x, int y)
{
	(void) 	x;
	(void)	y;
	return (0);
}

void	free_piece(t_piece *piece)
{
	if (piece == NULL)
		return ;
	mlx_destroy_image(data()->mlx, piece->img.img);
	free(piece);
}

static void	move(int x, int y)
{
	printf("x: %i  y: %i\n", x, y);
	if (!data()->select->check_move(x, y))
	{
		data()->select = NULL;
		return ;
	}
	data()->map[data()->select->x][data()->select->y] = NULL;
	data()->select->x = x;
	data()->select->y = y;
	free_piece(data()->map[x][y]);
	data()->map[data()->select->x][data()->select->y] = data()->select;
	data()->select->is_move = 1;
	data()->select = NULL;
	board_render();
}

t_piece *new_piece(int player, int x, int y)
{
	t_piece *piece = malloc(sizeof(t_piece));
	piece->player = player;
	piece->x = x;
	piece->y = y;
	piece->move = move;
	piece->check_move = check_move;
	data()->map[x][y] = piece;
	return piece;
}