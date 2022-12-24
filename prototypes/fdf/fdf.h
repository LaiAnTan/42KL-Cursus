#ifndef FDF_H

# define FDF_H

#  define BUFFER_SIZE 1000

# define WIDTH 1080

# define HEIGHT 720

# define PI 3.1415

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/X.h>
# include <stdint.h>

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			x_proj;
	int			y_proj;
	int			color;
}				t_point;

typedef struct s_matrix
{
	int			matrix[4][4];
}				t_matrix;

typedef struct s_map
{
	size_t		rows;
	size_t		cols;
	t_point		**points;
	t_matrix	transform;
}				t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_data
{

	void		*mlx_ptr;
	void		*win_ptr;

	t_img		img;
	t_map		map;
}				t_data;

/* 
locates the pixel's first byte address, and then 
buffers the pixel to a image, then 
puts that pixel on the screen
*/
void	mlx_img_put(t_img *img, int x, int y, int color);

// events
int		keypress_event(int key_symbol, t_data *data);
int		keyrelease_event(int key_symbol, void *data);

// render
int		render(t_data *data);

// map parsing
void	get_map(t_map *map, char *filename);

// ft_split
char	**ft_split(char const *s, char c);
int		countwords(char const *s, char c);

// get_next_line
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
int		check_nl(char *str, int size);
char	*transfer(int fd, char *buffer, char *content);
char	**seperate_nl(char *str);
char	*ft_append(char *s1, char *s2);
char	*ft_strdup_gnl(char *str);

// utils
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*trim_nl(char *line);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif