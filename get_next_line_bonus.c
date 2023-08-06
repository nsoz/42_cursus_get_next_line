/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:55:05 by muoz              #+#    #+#             */
/*   Updated: 2023/08/06 19:35:03 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_to_hold(int fd, char *holder)
{
	char	*buffer;
	int		readen_byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(holder);
		return (NULL);
	}
	readen_byte = 1;
	while (readen_byte != 0 && !ft_strchr(holder, '\n'))
	{
		readen_byte = read(fd, buffer, BUFFER_SIZE);
		if (readen_byte == -1)
		{
			free(holder);
			free(buffer);
			return (NULL);
		}
		buffer[readen_byte] = '\0';
		holder = ft_strjoin(holder, buffer);
	}
	free(buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder[10240];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	holder[fd] = read_to_hold(fd, holder[fd]);
	if (!holder[fd])
	{
		free(holder[fd]);
		return (NULL);
	}
	ret = get_holded_line(holder[fd]);
	holder[fd] = holder_refresher(holder[fd]);
	return (ret);
}
