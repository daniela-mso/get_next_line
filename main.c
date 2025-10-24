#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# include "get_next_line.h"

/**int main()
{
    char	*line;
	int	fd;

	fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error on opening file");
		return 1;
	}
	while ((line = get_next_line(fd)) != NULL) 
	{
        printf("Line: %s\n", line);
        free(line); 
	}
	close(fd);
    return 0;
}**/



// int main() {
//     int fd;
//     char *line;

//     // Test case 1: Open a valid file and read line by line
//     fd = open("test_file.txt", O_RDONLY);
//     if (fd == -1) {
//         perror(NULL);
//         return 1;
//     }

//     //printf("Reading lines from 'test_file.txt':\n");
//     while ((line = get_next_line(fd)) != NULL) {
//         //printf("Line: %s", line);
//         free(line); // Free the memory after using it
//     }
//     if (line == NULL) {
//         printf("End of file or error reached.\n");
//     }
//     close(fd);

//     // Test case 2: Invalid file descriptor (fd < 0)
//     // fd = -1;
//     // line = get_next_line(fd);
//     // if (line == NULL) {
//     //     printf("Handled invalid file descriptor (fd = -1)\n");
//     // }

//     // Test case 3: Open a non-existent file

//     // Test case 4: Empty file
//     // fd = open("empty.txt", O_RDONLY);
//     // if (fd == -1) {
//     //     perror("Error opening empty file");
//     // } else {
//     //     line = get_next_line(fd);
//     //     if (line == NULL) {
//     //         printf("No content in empty file.\n");
//     //     }
//     //     close(fd);
//     // }

//     return 0;
// } 
char *get_next_line(int fd);

int main(void)
{
	int fd = open("simple_3_lines.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)))
	{
		printf("LINE: %s", line);
		free(line);
	}
	printf("End of file or error reached.\n");

	close(fd);
	return 0;
}

int main(void)
{
	int fd = open("simple_3_lines.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return 1;
	}

	char *line;
	(line = get_next_line(fd))
	{
		printf("LINE: %s", line);
		free(line);
	}
	printf("End of file or error reached.\n");

	close(fd);
	return 0;
}





// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include "get_next_line.h"

// #ifndef O_RDONLY
// # define O_RDONLY 0
// #endif

// #ifndef FD_MAX
// # define FD_MAX 1024 
// #endif

// #define GNL_CALL 10000
// #define THEN_DIFF 1 

/*
static void     ft_display_stats(void)
{
        pthread_attr_t  attr;
        size_t                  stacksize;

        fprintf(stderr, ">> BUFFER_SIZE %d bytes", BUFFER_SIZE);
        fprintf(stderr, "  FD_MAX %d", FD_MAX);
        fprintf(stderr, "  GNL_CALL %d", GNL_CALL);
        pthread_attr_init(&attr);
        pthread_attr_getstacksize(&attr, &stacksize);
        fprintf(stderr, "  STACK SIZE %ld bytes\n", stacksize);
        pthread_attr_destroy(&attr);
}*/
// int    main()
// {
//         char                    *line;
//         int                             fd;
//         int                             i;

//         fd = open("test_file.txt", O_RDONLY);
//         if (fd == -1) {
// 			perror(NULL);
// 			 return (1);
// 		}
               
//         i = 0;
//         while (i++ < GNL_CALL)
//         {
//                 line = get_next_line(fd);
//                 if (!line)
//                         break ;
//                 if (THEN_DIFF)
//                         printf("%s", line);
//                 else
//                         printf("line [%02d]: %s", i, line);
//                 free(line);
//         }
//         close(fd);
//         return (0);
// }