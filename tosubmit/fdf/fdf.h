/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:32:37 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/17 12:19:50 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# define BUFFER_SIZE 10000

# define WIDTH 1080

# define HEIGHT 720

# define WHITE 0x00FFFFFF;

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdint.h>

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	float			x_proj;
	float			y_proj;
	unsigned int	color;
}				t_point;

typedef struct s_line
{
	float			x0;
	float			y0;
	float			x1;
	float			y1;
	unsigned int	color0;
	unsigned int	color1;
}				t_line;

typedef struct s_map
{
	size_t		rows;
	size_t		cols;
	t_point		**points;
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
	t_line		line;
}				t_data;

/* 
locates the pixel's first byte address, and then 
buffers the pixel to a image, then 
puts that pixel on the screen
*/
void	mlx_img_put(t_img *img, int x, int y, int color);

// render
void	draw_vertical_lines(t_data *data);
void	draw_horizontal_lines(t_data *data);
void	place_points(t_data *data);
int		clear_screen(t_data *data);

// events
int		keypress_event(int key_symbol, t_data *data);

// coordinates related stuff
void	assign_xy(t_map *map, int distance, int x_offset, int y_offset);
void	translate(t_map *map, int x_offset, int y_offset);
void	zoom(t_map *map, float zoom);
void	iso_project(t_map *map, float cos_angle, float sin_angle);

// line drawing
// uses the variables in the t_line struct found inside t_data to draw line
void	bressenham(t_data *data);
// edge case for bresenhams line drawing algorithm
void	vertical(t_data *data);

// color stuff
int		encode_trgb(int transparency, int red, int green, int blue);
int		*dec_to_rgb(int rgb[3], unsigned int dec);
int		get_gradient(t_line *line, float x, float y);

// render
int		render(t_data *data);

// map parsing
/*
function that reads a file line by line,
extracts the contents (z pos and color) in the line, then
inputs them into the struct t_map
returns 0 on success and -1 on fail
*/
int		get_map(t_map *map, char *filename);
int		*count_dimension(char *filename);
int		get_color(char *str_color);
void	get_dimension(t_map *map, char *filename);
void	malloc_map(t_map *map);

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
int		is_present(char *str, char c);
char	*ft_strdup(char *str);
char	*trim_nl(char *line);
char	*ft_substr(const char *s, unsigned int start, size_t len);

int		clean_exit(t_data *data);

#endif