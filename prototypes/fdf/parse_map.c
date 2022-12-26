#include "fdf.h"

char	*trim_nl(char *line)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (line == NULL)
		return (NULL);
	if (is_present(line, '\n') == 0)
		return (line);
	len = ft_strlen(line);
	ret = (char *) malloc (sizeof(char) * len);
	while (line[i] != '\n')
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	free(line);
	return (ret);
}

int		get_color(char *str_color)
{
	// eg: 0xFFFF00FF
	int		base;
	int		index;
	unsigned int	hex_color;

	base = 1;
	index = ft_strlen(str_color) - 1;
	hex_color = 0;
	while (index >= 2)
	{
		if (str_color[index] >= 'A' && str_color[index] <= 'F')
			hex_color += (str_color[index] - 55) * base;
		else if (str_color[index] >= 'a' && str_color[index] <= 'f')
			hex_color += (str_color[index] - 87) * base;
		else if (str_color[index] >= '0' && str_color[index] <= '9')
			hex_color += (str_color[index] - 48) * base;
		base *= 16;
		index--;
	}
	return (hex_color);
}

int		*count_dimension(char *filename)
{
	int		fd;
	int		row_len;
	int		col_len;
	char	*line;
	int		*rc;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	col_len = countwords((char *) line, ' ');
	row_len = 1;
	rc = (int *) malloc (sizeof(int) * 2);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (countwords((char *) line, ' ') != col_len)
		{
			row_len = -1;
			col_len = -1;
			break;
		}
		free(line);
		row_len++;
	}
	close(fd);
	rc[0] = row_len;
	rc[1] = col_len;
	return (rc);
}

int		get_dimension(t_map *map, char *filename)
{
	int		*rc;

	rc = count_dimension(filename);
	map ->rows = rc[0];
	map ->cols = rc[1];
	printf("rows: %ld, cols: %ld\n", map ->rows, map ->cols);
	free(rc);
}

	/*
					col_0	col_1	col_2	col_3
	map ->points = {"	",	"	",	"	",	"	"}
					  |		  |		  |		  |
				  	"	"	"	"	"	"	"	"	row_0
					  |		  |		  |		  |
				  	"	"	"	"	"	"	"	"	row_1
					  |		  |		  |		  |
				  	"	"	" X	"	"	"	"	"	row_2
					  |		  |		  |		  |
				  	"	"	"	"	"	"	"	"	row_3

	Therefore, points[col][row]
	eg: points[2][3] = col 1, row 2
	*/

void	malloc_map(t_map *map)
{
	int		i;

	i = 0;
	map ->points = (t_point **) malloc (sizeof(t_point *) * map ->cols);
	while (i < map ->cols)
	{
		map ->points[i] = (t_point *) malloc (sizeof(t_point) * map ->rows);
		i++;
	}
}

void	free_2d_array(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	extract_insert_data(t_point	**points, char *line, int row, int col)
{
	int		i;
	char	**split;
	char	**split_2;

	i = 0;
	split = ft_split((char *) line, ' ');
	while (i < col)
	{
		if (is_present(split[i], ',') == 1)
		{
			split_2 = ft_split(split[i], ',');
			if (split_2[0] != NULL)
				points[i][row].z = ft_atoi(split_2[0]);
			if (split_2[1] != NULL)
				points[i][row].color = get_color(split_2[1]);
			else
				points[i][row].color = WHITE;
			free_2d_array(split_2);
		}
		else
		{
			if (split[i] != NULL)
				points[i][row].z = ft_atoi(split[i]);
			points[i][row].color = WHITE;
		}
		i++;
	}
	free_2d_array(split);
	
}

int		get_map(t_map *map, char *filename)
{	
	int		i;
	int		fd;
	char	*line;

	get_dimension(map, filename);
	if (map ->rows == -1 && map ->cols == -1)
		return (-1);
	malloc_map(map);

	i = 0;
	fd = open(filename, O_RDONLY);
	while (i < map ->rows)
	{
		line = get_next_line(fd);
		line = trim_nl(line);
		if (!line)
			break;
		extract_insert_data(map ->points, line, i, map ->cols);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

