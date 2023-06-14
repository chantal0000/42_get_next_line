/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:55:55 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/13 15:58:45 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*malloc and free*/
# include <stdlib.h>
/*read*/
# include <unistd.h>

/*define the required constant BUFFER_SIZE */

# ifndef BUFFER_SIZE
/*if not defined BUFFER_SIZE is 1000 */
# define BUFFER_SIZE 1000
# endif

/*get_next_line*/
char	*ft_read_str(int fd, char *str);
char	*get_next_line(int fd);
/*get_next_line_utils*/
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_extract_line(char *stat_str);
char	*ft_new_stat_str(char *stat_str);
#endif
