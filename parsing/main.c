#include "../includes/cube.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		fd;


	// check at first if the argument is correct (valid file)
	check_argument(argc, argv[1], &fd);

	data = (t_data *)malloc(sizeof(t_data));
	init(data);
	if (malloc_all(data) == ERROR)
		ft_error(data, "Malloc error");

	// read the file and check the content
	parsing(data, fd);

	//exec(data);
	return (0);
}
