#include "includes/application.h"

extern t_data data;
const char *g_text;

void on_text_entry_changed(Tool *widget, Pointer user_data)
{
	g_text = gtk_entry_get_text(GTK_ENTRY(widget));
}

void on_button_click0(Tool *widget, Pointer user_data)
{
	char *path = "map/map4.ber";
	int fd;

	fd = ft_fopen(path, "r");
	data.name = g_text;
	display(ft_fopen(path, "r"), &data);
	data.map = create_map(fd, &data);
	Window *dados = new_window("Nivel 0", (data.win_width + 2) * SIZE_Q, (data.win_height + 2) * SIZE_Q);
		ft_render_form1(dados, &data);
	loop(dados);
}

void on_button_click1(Tool *widget, Pointer user_data)
{
	char *path = "map/map4.ber";
	int fd;

	fd = ft_fopen(path, "r");
	data.name = g_text;
	display(ft_fopen(path, "r"), &data);
	data.map = create_map(fd, &data);
	Window *dados = new_window("Nivel 0", (data.win_width + 2) * SIZE_Q, (data.win_height + 2) * SIZE_Q);
		ft_render_form1(dados, &data);
	loop(dados);
}

void on_button_click2(Tool *widget, Pointer user_data)
{
	char *path = "map/map4.ber";
	int fd;

	fd = ft_fopen(path, "r");
	data.name = g_text;
	display(ft_fopen(path, "r"), &data);
	data.map = create_map(fd, &data);
	Window *dados = new_window("Nivel 0", (data.win_width + 2) * SIZE_Q, (data.win_height + 2) * SIZE_Q);
		ft_render_form1(dados, &data);
	loop(dados);
}

static void	set_derection(int keysym, t_data *data)
{
	if (keysym == 65364)
	{
		data->cadete.direction = 'T';
		data->cadete.img = "textures/T/player1.xpm";
	}
	else if (keysym == 65362)
	{
		data->cadete.direction = 'F';
		data->cadete.img = "textures/F/player1.xpm";
	}
	else if (keysym == 65363)
	{
		data->cadete.direction = 'E';
		data->cadete.img = "textures/E/player1.xpm";
	}
	else if (keysym == 65361)
	{
		data->cadete.direction = 'D';
		data->cadete.img = "textures/D/player1.xpm";
	}
}

static int	move_cadete(int *i, int *current_x, int *current_y, t_data *d)
{
	if (d->cadete.pos_x == d->map[*i].pos_x
		&& d->cadete.pos_y == d->map[*i].pos_y)
	{
		if (d->map[*i].value == '1')
		{
			d->cadete.pos_x = *current_x;
			d->cadete.pos_y = *current_y;
			return (d->cadete.pass--, 1);
		}
		else if (d->map[*i].value == 'C')
		{
			d->map[*i].value = '0';
			d->score++;
		}
	}
	return (0);
}

static int	press_w_a_s_d(int keysym, t_data *data)
{
	if (keysym == 65362)
		data->cadete.pos_y -= SIZE_Q;
	else if (keysym == 65364)
		data->cadete.pos_y += SIZE_Q;
	else if (keysym == 65361)
		data->cadete.pos_x -= SIZE_Q;
	else if (keysym == 65363)
		data->cadete.pos_x += SIZE_Q;
	set_derection(keysym, data);
	return (1);
}


gboolean on_key_press(Tool *widget, EventKey *event, Pointer user_data) 
{
	int	tmp_x;
	int	tmp_y;
	int	i;
	int	flg;

	i = 0;
	tmp_x = data.cadete.pos_x;
	tmp_y = data.cadete.pos_y;
	data.cadete.pass++;

	if (event->keyval == GDK_KEY_q) 
	{ 
		g_print("Tecla 'q' pressionada! Saindo...\n");
		gtk_main_quit(); 
		return (TRUE); 
	}
	
	press_w_a_s_d((int)event->keyval, &data);
	while (i < data.win_width * data.win_height)
	{
		move_cadete(&i, &tmp_x, &tmp_y, &data);
		i++;
	}

	//render_map(&data, user_data, 0);
	Label		*label1 = create_label_with_position(user_data, "ok", 4, 4, NULL);
	return (FALSE); 
}