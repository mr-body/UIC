#include "includes/application.h"

t_data data;

gboolean	on_loop(Pointer user_data)
{
	return (TRUE);
}

int main(int argc, char *argv[])
{
	Application(argc, argv);

		Window  *window = create_window("So_long", 700, 400);
		ft_render_objects(window);
		g_timeout_add(1000, on_loop, NULL); 

	loop(window);
	return 0;
}