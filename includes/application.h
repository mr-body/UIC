#include "../lib/libsf.h"
#include "../lib/libft.h"
# include "structs.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void ft_render_objects(Window  *window);
void ft_render_form1(Window  *window, t_data *data);

void on_button_click0(Tool *widget, Pointer user_data);
void on_button_click1(Tool *widget, Pointer user_data);
void on_button_click2(Tool *widget, Pointer user_data);

void on_text_entry_changed(Tool *widget, Pointer user_data);
gboolean on_key_press(Tool *widget, EventKey *event, Pointer user_data);



void	display(int fd, t_data *data);
t_map	*create_map(int fd, t_data *data);
void	render_map(t_data *data, Panel *fixed, int time);