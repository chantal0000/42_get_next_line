/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:49:21 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/13 16:02:02 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*count the length of the string*/
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*The  strchr() function returns a pointer to the first 
  occurrence of the character c in the string s.*/
/*char	*ft_strchr(const char *s, int c)
{
	char	*new;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			new = &s[i];
			return (new);
		}
		else
		i++;
	}
	return (NULL);
}*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *) s);
	return ((char *) NULL);
}

/**/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	ft_memcpy(new_str, s1, s1_len);
	ft_memcpy(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}
/*needed for ft_strjoin*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*ptr_dest;
	const char	*ptr_src;

	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (ptr_dest);
}

/*extract line and search for the end*/

char	*ft_extract_line(char *stat_str)
{
	size_t	i;
	char	*new_str;

	i = 0;
	if (stat_str == NULL)
		return (NULL);
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * i + 1);
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
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (stat_str[i] && stat_str[i] != '\n')
		i++;
	if (stat_str[i] == '\0')
	{
		free(stat_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stat_str) - i + 1));
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
