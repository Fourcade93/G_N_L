#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	// fd = open(av[1], O_WRONLY);
	// ft_putstr_fd(av[2], fd);
	// ft_putstr_fd(av[3], fd);
	// close(fd);
	fd = open(av[1], O_RDONLY);
	while (!get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}
