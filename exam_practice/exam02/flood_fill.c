# include <stdio.h>
# include <stdlib.h>

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point curr, char to_fill)
{
	if (curr.y < 0 || curr.y >= size.y || curr.x < 0 
			|| curr.x >= size.x || tab[curr.x][curr.y] != to_fill)
		return;
	
	tab[curr.x][curr.y] = 'F';
	fill(tab, size, (t_point){curr.x - 1, curr.y}, to_fill);
	fill(tab, size, (t_point){curr.x + 1, curr.y}, to_fill);
	fill(tab, size, (t_point){curr.x, curr.y - 1}, to_fill);
	fill(tab, size, (t_point){curr.x, curr.y + 1}, to_fill);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

/*
tab[y][x];
*/
int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}