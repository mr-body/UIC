# define SIZE_Q 30

typedef struct s_map{
	void	*img;
	char	value;
	int		pos_x;
	int		pos_y;
}	t_map;

typedef struct s_soldier{
	void	*img;
	char	soldier;
	int		pos_x;
	char	*shadow;
	int		shadow_inter;
	int		pos_y;
}	t_soldier;

typedef struct s_cadete{
	void	*img;
	char	*img_old;
	char	soldier;
	char	direction;
	int		pos_x;
	int		pos_y;
	int		pass;
}	t_cadete;



typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			coin;
	int			score;
	int			end;
	char		*name;
	char		*path;
	t_map		*map;
	t_soldier	soldier;
	t_cadete	cadete;
}	t_data;