#include "../headers/chess.h"

void	board_render(int x, int y, int counter)
{
	t_data_img *data_img;
	while (x < 8)
	{
		y = 0;
		if (counter == 0)
			counter = 1;
		else
			counter = 0;
		while (y < 8)
		{
			if (counter == 0)
			{
				data_img = &data()->floor[0];
				counter = 1;
			}
			else
			{
				data_img = &data()->floor[1];
				counter = 0;
			}
			print_img(*data_img, x * 100, y *100);
			if (data()->map[x][y])
				print_img(data()->map[x][y]->img, x * 100, y *100);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data()->mlx, data()->win, data()->canva.img, 0 , 0);
}
