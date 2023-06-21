/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:49:21 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/21 17:00:30 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*count the length of the string*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

/*ft_strjoin*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

/*extract line and search for the end*/

char	*ft_extract_line(char *stat_str)
{
	int		i;
	char	*new_str;

	i = 0;
	if (stat_str == NULL)
		return (NULL);
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 2));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (stat_str[i] && stat_str[i] != '\n')
	{
		new_str[i] = stat_str[i];
		i++;
	}
	if (stat_str[i] == '\n')
	{
		new_str[i] = stat_str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*create new str by removing the extracted line from the original*/

char	*ft_new_stat_str(char *stat_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (stat_str == NULL)
		return (NULL);
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	if (stat_str[i] == '\0')
	{
		free(stat_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stat_str) - i));
	if (str == NULL)
		return (NULL);
	i++;
	j = 0;
	while (stat_str[i])
		str[j++] = stat_str[i++];
	str[j] = '\0';
	free(stat_str);
	return (str);
}
