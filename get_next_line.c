#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>


       


// char *get_next_line(int fd)
// {
//     if (fd < 0)
//         return NULL;
    
//     char *lido = malloc(sizeof(char) * 5 + 1);
//     if (!lido)
//         return NULL;

//     char *string = NULL;
//     ssize_t num_b;

//     while ((num_b = read(fd, lido, 5)) > 0)
//     {
//         lido[num_b] = '\0';  
//         char *temp = ft_strjoin(string, lido);
//         free(string);        
//         string = temp;

//         if (ft_strchr(lido, '\n')) 
//             break;
//     }

//     free(lido);

//     if (!string || *string == '\0')
//     {
//         free(string);
//         return NULL;
//     }
//     return string;
// }






// #define BUFFER_SIZE 5

// char *get_next_line(int fd)
// {
//     static char *remainder; 
//     char *lido;
//     char *line;
//     char *temp;
//     ssize_t num_b;

//     if (fd < 0)
//         return NULL;

//     lido = malloc(BUFFER_SIZE + 1);
//     if (!lido)
//         return NULL;

//     while ((num_b = read(fd, lido, BUFFER_SIZE)) > 0)
//     {
//         lido[num_b] = '\0';
//         temp = ft_strjoin(remainder, lido);
//         free(remainder);
//         remainder = temp;

//         if (ft_strchr(lido, '\n'))
//             break;
//     }

//     free(lido);

//     if (!remainder || *remainder == '\0')
//     {
//         free(remainder);
//         remainder = NULL;
//         return NULL;
//     }

//     int i = 0;
//     while (remainder[i] && remainder[i] != '\n')
//         i++;

//     if (remainder[i] == '\n')
//         i++;

//     line = malloc(i + 1);
//     if (!line)
//         return NULL;







//     line[i] = '\0';

//     temp = ft_strjoin(remainder + i, "");
//     free(remainder);
//     remainder = temp;

//     return line;
// }



// char *get_next_line(int fd)
// {
//     if (fd < 0)
//         return NULL;

//     char *lido = malloc(sizeof(char) * 6); 
//     if (!lido)
//         return NULL;

//     char *string = NULL;
//     ssize_t num_b;

//     num_b = read(fd, lido, 6);
//     if (num_b <= 0)
//     {
//         free(lido);
//         return NULL;
//     }

//     lido[num_b] = '\0';
//     string = ft_strjoin(NULL, lido); 
//     free(lido);

//     return string;
// }







char *get_next_line(int fd)
{
    static char *string;  
    char *lido;           
    char *line;           
    char *temp;
    ssize_t num_b;

    if (fd < 0 )
        return NULL;

    lido = malloc(BUFFER_SIZE + 1);
    if (!lido)
        return NULL;


    while ((num_b = read(fd, lido, BUFFER_SIZE)) > 0)
    {
        lido[num_b] = '\0';

        temp = ft_strjoin(string, lido); 
        free(string);
        string = temp;

        if (ft_strchr(lido, '\n'))       
            break;
    }

    free(lido);

    if (!string || *string == '\0')     
        return NULL;


    int i = 0;
    while (string[i] && string[i] != '\n')
        i++;
    if (string[i] == '\n')
        i++;

    line = malloc(i + 1);
    if (!line)
        return NULL;

    int j = 0;
    while (j < i)                          
    {
        line[j] = string[j];
        j++;
    }
    line[i] = '\0';

    temp = ft_strjoin(string + i, "");
    free(string);
    string = temp;

    return line;
}


// Return value Read line: correct behavior
// NULL: there is nothing else to read, or an error
// occurred
// External functs. read, malloc, free
// Description Write a function that returns a line read from a
// file descriptor





//int main(void)
