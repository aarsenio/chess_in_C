#include "../headers/chess.h"

static void	__pixel(int x, int y, int color)
{
	char		*dst;
	t_data_img	*data_img;

	if (color == COLOR_TRANSPARENT || (x >= 800 || y >= 800))
		return ;
	data_img = &data()->canva;
	dst = data_img->addr + (y * data_img->line_length + x \
	* (data_img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	__get_color_img(t_data_img	data, int x, int y)
{
	char		*dst;
	int			color;

	dst = data.addr + (y * data.line_length + x \
	* (data.bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void print_img(t_data_img	data, int x1, int y1)
{
	int x;
	int y;

	x = -1;
	while (++x < data.w)
	{
		y = -1;
		while (++y < data.h)
		{
			__pixel(x1 + x, y1 + y, __get_color_img(data, x, y));
		}
	}
}

void new_canva()
{
	data()->canva.img = mlx_new_image(data()->mlx, 800, 800);
	data()->canva.addr = mlx_get_data_addr(data()->canva.img, &data()->canva.bits_per_pixel, \
	&data()->canva.line_length, &data()->canva.endian);
}

void load_img(char *file, t_data_img *img)
{
	img->img = mlx_xpm_file_to_image(data()->mlx, file, &img->w, &img->h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
}
