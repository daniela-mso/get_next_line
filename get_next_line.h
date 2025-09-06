#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H



# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 5


char *get_next_line(int fd);
int ft_strlen(const char *str);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);

#endif