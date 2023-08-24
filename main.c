#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_next_line.h"

int	main(void)
{
	char *file_name;
	int fd;
	file_name = "teste.txt";

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);

	while (1)
	{
		char *line;
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		usleep(5000);
		free(line);
	}
	close(fd);
	return(0);
}