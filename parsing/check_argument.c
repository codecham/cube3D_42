#include "../includes/cube.h"

/*
Ce fichier contient une fonction qui va vérifier:
- Si le nombre d'argument est correct
- Si le format du fichier est bien .cub
- Si c'est un fichier qui peut se lire.

Je pense qu'on peut l'utiliser dans le debut du main :-)
*/


/* check the command line argument */
void	check_argument(int argc, char *path, int *fd)
{
	int	len;

	if (argc != 2)
	{
		ft_printf("Error\n: Incorrect number of arguments\n");
		exit(1);
	}
	len = ft_strlen(path);
	if (path[len - 1] != 'b' || path[len - 2] != 'u' \
		|| path[len - 3] != 'c' || path[len - 4] != '.')
	{
		ft_printf("Error\n: Invalid file format\n");
		exit(1);
	}
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
}
