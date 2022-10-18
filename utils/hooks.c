#include "../headers/chess.h"

int	key(int keycode, void *param)
{

	(void) param;
	if (keycode == 65307)
		print_error("Quit Game", 0);
	return (0);
}

int	mouse(int event, void *param)
{
	int				x = 0;
	int 			y = 0;

	(void) param;
	if (event != 1)
		return (0);
	mlx_mouse_get_pos(data()->mlx, data()->win, &x, &y);
	x /= 100;
	y /= 100;
	if (data()->select && data()->select->move)
		data()->select->move(x, y);
	else
		data()->select = data()->map[x][y];	
	return (0);
}