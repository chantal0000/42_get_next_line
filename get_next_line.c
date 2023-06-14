/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:19:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/13 15:43:45 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*read, malloc and free*/

#include "get_next_line.h"

char	*ft_read_str(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}




char	*get_next_line(int fd)
{
	char		*line;
	static char *static_str;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_str = ft_read_str(fd, static_str);
	if (static_str == NULL)
		return (NULL);
	line = ft_extract_line(static_str);
	static_str = ft_new_stat_str(static_str);	
// returns a string of characters
	return (line);
}

/*test main function*/

#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test1.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open file\n");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
