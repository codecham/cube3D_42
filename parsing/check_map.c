#include "../includes/cube.h"


/*
Check if the character is valid for the game.
(the character must be in {'N', 'S', 'E', 'W', '0', '1'})
*/
int	char_is_valid(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	if (c == '0' || c == '1')
		return (1);
	return (0);
}

/* Check if the char array contains only '1' */
int	line_is_wall(char *one_line)
{
	int	i;

	i = 0;
	if (one_line == NULL)
		return (0);
	while (one_line[i] != '\0' && one_line[i] != '\n')
	{
		if (one_line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_data *data, int	fd)
{
	// je voulais lire chaque ligne avec get_next_line puis checker si c'est valid
	// mais pas reussi sorry;;

	// les 2 fonctions en haut sont peut-être util pour checker une ligne...
}
