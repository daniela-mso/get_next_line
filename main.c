#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# include "get_next_line.h"

char *get_next_line(int fd);

// int main(void)
// {
// 	char	*line;
//     int fd;
	
// 	fd = open("simple_3_lines.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("open");
//         return 1;
//     }
//     while ((line = get_next_line(fd)))
//     {
//         printf("LINE: %s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }

// int main()
// {
// 	int fd = open("simple_3_lines.txt", O_RDONLY);
// 	char *line;
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return 0;
// }
//
//
//
//
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
    char *line;

    while ((line = get_next_line(0)) != NULL)  // read from stdin
    {
        printf("%s", line);
        free(line);
    }

    // Cleanup: free static stash inside GNL
    get_next_line(-1);

    return 0;
}