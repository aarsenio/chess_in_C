#include "../headers/chess.h"

int	exit_game()
{
	int	x;
	int y;

	x = -1;
	while (++x < 8)
	{
		y = -1;
		while (++y < 8)
		{
			if (data()->map[x][y])
				free(data()->map[x][y]);
		}
	}
	x = 0;
	if (data()->win)
		mlx_destroy_window(data()->mlx, data()->win);
	if (data()->mlx)
	{
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	exit (0);
}

void	print_error(char *str, int error)
{
	int	i;

	i = 0;
	if (error)
		write(1, "Error\n", 7);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit_game();
}
