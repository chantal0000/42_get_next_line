/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:16:40 by chbuerge          #+#    #+#             */
/*   Updated: 2023/06/21 17:01:00 by chbuerge         ###   ########.fr       */
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
#  define BUFFER_SIZE 1000
# endif

/*get_next_line*/
char	*ft_read_str(int fd, char *str);
char	*get_next_line(int fd);
/*get_next_line_utils*/
int		ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract_line(char *stat_str);
char	*ft_new_stat_str(char *stat_str);
#endif
