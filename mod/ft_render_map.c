#include "../includes/application.h"

static char	*push_image(char value, t_data *data)
{
	if (data->end != 1)
	{
		if (value == '1')
			return ("textures/parede.xpm");
		else if (value == 'P')
			return ("textures/porta.xpm");
		else if (value == 'C')
			return ("textures/sopa.xpm");
		else if (value == 'E')
			return ("textures/pc.xpm");
		else if (value == '0')
			return ("textures/fundo.xpm");
		return (NULL);
	}
	return ("textures/fundo.xpm");
}

static char	*animation(t_data *data)
{
	if (data->cadete.direction == 'D'
		&& !ft_strncmp(data->cadete.img_old, "textures/D/player1.xpm", 20))
	{
		data->cadete.img_old = "textures/D/player2.xpm";
		return ("textures/D/player2.xpm");
	}
	if (data->cadete.direction == 'F'
		&& !ft_strncmp(data->cadete.img_old, "textures/F/player1.xpm", 20))
	{
		data->cadete.img_old = "textures/F/player2.xpm";
		return ("textures/F/player2.xpm");
	}
	if (data->cadete.direction == 'T'
		&& !ft_strncmp(data->cadete.img_old, "textures/T/player1.xpm", 20))
	{
		data->cadete.img_old = "textures/T/player2.xpm";
		return ("textures/T/player2.xpm");
	}
	if (data->cadete.direction == 'E'
		&& !ft_strncmp(data->cadete.img_old, "textures/E/player1.xpm", 20))
	{
		data->cadete.img_old = "textures/E/player2.xpm";
		return ("textures/E/player2.xpm");
	}
	return (data->cadete.img);
}

void	render_objs(Panel *fixed, int *i,  int *j, int *k, t_data *data)
{
	char	*image_path;
	int		width;
	int		height;

	if (*j > data->win_width * SIZE_Q)
	{
		*k += SIZE_Q;
		*j = SIZE_Q;
	}
	if (data->map[*i].value != 0)
	{
		data->map[*i].pos_x = *j;
		data->map[*i].pos_y = *k;
		image_path = push_image(data->map[*i].value, data);
		if (image_path != NULL)
            create_image_with_position(fixed, image_path, data->map[*i].pos_x, data->map[*i].pos_y,  30, 30);
	}
	*j += SIZE_Q;
}

void	render_map(t_data *data, Panel *fixed, int time)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = SIZE_Q;
	k = SIZE_Q;
	while (++i < data->win_width * data->win_height)
	{
		render_objs(fixed, &i, &j, &k, data);
		if (time == 1)
			usleep(6000);
	}
	data->cadete.img_old = animation(data);
	create_image_with_position(fixed, data->cadete.img_old, data->cadete.pos_x, data->cadete.pos_y,  30, 30);
}