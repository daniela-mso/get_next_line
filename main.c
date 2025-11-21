#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# include "get_next_line.h"

// int main()
// {
// 	int line_n = 1;
// 	char *line;
// 	while ((line = get_next_line(STDIN_FILENO)) != NULL)
// 	{
// 		printf("LINE%d: %s", line_n ,line);
// 		free(line);
// 		line_n++;
// 	}
// 	return 0;
// }







char *get_next_line(int fd);

// int main(void)
// {
// 	int fd = open("simple_3_lines.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return 1;
// 	}

// 	char *line;
// 	// while ((line = get_next_line(fd)))
// 	// {
// 	// 	printf("LINE: %s", line);
// 	// 	free(line);
// 	// }
// 	line = get_next_line(fd);
// 	printf("LINE: %s", line);

// 	line = get_next_line(fd);
// 	printf("LINE: %s", line);

// 	line = get_next_line(fd);
// 	printf("LINE: %s", line);

// 	//printf("End of file or error reached.\n");

// 	close(fd);
// 	return 0;
// }


int main(void)
{
    int fd = open("simple_3_lines.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 1;
    }
    
    char *line;

    // Loop through all lines until get_next_line returns NULL
    while ((line = get_next_line(fd)))
    {
        printf("LINE: %s", line); // Print the line
        free(line);  // Free the allocated memory for the line to prevent leaks
    }

    close(fd); // Close the file descriptor
    return 0;
}