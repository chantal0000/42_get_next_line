/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:19:03 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/21 17:20:23 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*new*/
static char	*free_str(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static void	ft_join(char **str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(*str, buffer);
	free_str(str);
	*str = temp;
}
/*end new*/

char	*ft_read_str(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buffer[read_bytes] = '\0';
		if (!str)
			str = ft_strjoin("", buffer);
		else
			ft_join(&str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (read_bytes == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str = ft_read_str(fd, static_str);
	if (!static_str || !*static_str)
	{
		free_str(&static_str);
		return (NULL);
	}
	line = ft_extract_line(static_str);
	static_str = ft_new_stat_str(static_str);
	return (line);
}

/*test main function*/

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char	*temp;
	int	fd;

	fd = open("test1.txt", O_RDONLY);

	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
		break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
}

/*
int	main(void)
{
    int fd = open("test1.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("Failed to open file\n");
        return 1;
    }
	printf("%s\n", get_next_line(fd));
	
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}*/
