#include "../headers/chess.h"

void	board_render()
{
	int x;
	int y;

	print_img(data()->board, 0, 0);
	if (data()->select)
		print_img(data()->select_img, data()->select->x * 100, data()->select->y *100);
	x = -1;
	while (++x < 8)
	{
		y = -1;
		while (++y < 8)
			if (data()->map[x][y])
				print_img(data()->map[x][y]->img, x * 100, y *100);
	}
	
	mlx_put_image_to_window(data()->mlx, data()->win, data()->canva.img, 0 , 0);
}
