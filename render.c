#include "includes/application.h"

void ft_render_objects(Window  *window)
{
	Panel		*fixed = add_fixed_layout_to_window(window);

	Button		*button1 = create_button_with_position(fixed, "               Nivel 0               ", 30, 230, on_button_click0, NULL);
	Button		*button2 = create_button_with_position(fixed, "               Nivel 1               ", 30, 280, on_button_click1, NULL);
	Button		*button3 = create_button_with_position(fixed, "               Nivel 2               ", 30, 330, on_button_click2, NULL);

	Label		*label1 = create_label_with_position(fixed, "SO_LONG", 30, 30, NULL);
	Label		*label2 = create_label_with_position(fixed, "Selecione um Map para iniciar um novo Jogo", 30, 100, NULL);
	Label		*label3 = create_label_with_position(fixed, "Informe o seu nome *", 30, 160, NULL);

	Image		*image1 = create_image_with_position(fixed, "./assets/200w.gif", 380, 160,  250, 250);

	Textbox		*textbox1 = add_entry(fixed, 30, 190, f(on_text_entry_changed));

	Style *label1_style = "label { color: green; font-size: 50px}";
	Style *label2_style = "label { color: white; font-size: 18px}";
	Style *label3_style = "label { color: white; font-size: 14px}";


	Style *textbox1_style = "entry { color: green; border: none; background: #dddd;}";
	
	apply_css(label1, label1_style);
	apply_css(label2, label2_style);
	apply_css(label3, label3_style);

	apply_css(textbox1, textbox1_style);

}


void ft_render_form1(Window  *window, t_data *data)
{
	Panel		*fixed = add_fixed_layout_to_window(window);

	hook(window, KEY_PRESS_EVENT, f(on_key_press), fixed);
	
	render_map(data, fixed, 0);

	//char *nome = ft_strlcat("Jogador: ", data->name, (size_t)ft_strlen(data->name));
	
	Label		*label1 = create_label_with_position(fixed, data->name, 4, 4, NULL);
	apply_css(label1, "label { color: green; font-size: 14px}");
}
