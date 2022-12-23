#include "fdf.h"

int		*count_dimension(char *filename)
{
	int		fd;
	int		row_len;
	int		col_len;
	char	*line;
	int		*rc;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	row_len = countwords((char *) line, ' ');
	col_len = 1;
	rc = (int *) malloc (sizeof(int) * 2);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (countwords((char *) line, ' ') != row_len)
			row_len = -1;
		free(line);
		col_len++;
	}
	close(fd);
	rc[0] = row_len;
	rc[1] = col_len;
	return (rc);
}

void	get_dimension(t_map *map, char *filename)
{
	int		*rc;

	rc = count_dimension(filename);
	map ->rows = rc[0];
	map ->cols = rc[1];
	free(rc);
}

void	malloc_map(t_map *map)
{
	int		i;

	i = -1;
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
	map ->points = (t_point **) malloc (sizeof(t_point *) * map ->cols);
	while (i++ < map ->cols)
		map ->points[i] = (t_point *) malloc (sizeof(t_point) * map ->rows);
}

void	extract_insert_data(t_point	**points, char *line, int row, int col)
{
	int		i;
	char	**split;
	char	**split_2;

	i = 0;
	// splits the line into chunks of z values (15) or z values and color (15,0xFF0000)
	split = ft_split((char *) line, ' ');
	for (int x = 0; x <= col; x++)
		printf("split[%d] = %s\n",x , split[x]);
	while (i < row)
	{
		// splits every chunk again and check if it was splitted to seperate z value and color
		// split_2 = ft_split(split[i], ',');
		// for (int x = 0; x < 2; x++)
		// 	printf("split_2 = %s\n", split_2[x]);
		points[i][row].z = ft_atoi(split[0]);
		printf("i = %d, row = %d, val = %d\n", i, row, points[i][row].z);
		// points[i][row].color = atoi(ft_strdup(split_2[1]));
		// free(split_2[0]);
		// free(split_2[1]);
		// free(split_2);
		free(split[i]);
		i++;
	}
	free(split);
}

void	get_map(t_map *map, char *filename)
{	
	int		i;
	int		fd;
	char	*line;

	get_dimension(map, filename);
	printf("row = %ld, col = %ld\n",map ->rows, map ->cols);
	if (map ->rows == -1)
		return ;
	malloc_map(map);

	i = 0;
	fd = open(filename, O_RDONLY);
	while (i < map ->rows)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		extract_insert_data(map ->points, line, i, map ->cols);
		free(line);
		i++;
	}
	close(fd);
}