#include "../includes/cube.h"

int	is_identifier(char *line)
{
	int	i;

	i = 0;
	if (line[0] == 'N' && line[1] == 'O' && line[1] == ' ')
		return (1);
	if (line[0] == 'S' && line[1] == 'O' && line[1] == ' ')
		return (1);
	if (line[0] == 'W' && line[1] == 'E' && line[1] == ' ')
		return (1);
	if (line[0] == 'E' && line[1] == 'A' && line[1] == ' ')
		return (1);
	if (line[0] == 'F' && line[1] == ' ')
		return (1);
	if (line[0] == 'C' && line[1] == ' ')
		return (1);
	return (0);
}

/*
void	get_information(char *one_line, t_data *data)
{
	assign the information to data structure
}
*/

void	parsing(t_data *data, int fd)
{
	char	*one_line;

	one_line = get_next_line(fd);
	while (one_line != NULL)
	{
		if (is_identifier(one_line))
			//get_information(one_line, data);
		else
			// the line is empty or map
		one_line = get_next_line(fd);
	}

	close(fd);
}
