/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:55:09 by muoz              #+#    #+#             */
/*   Updated: 2023/08/06 16:55:10 by muoz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *holder, char *str)
{
	int		i;
	int		j;
	char	*s;

	if (!holder)
	{
		holder = malloc(sizeof(char) * 1);
		holder[0] = '\0';
	}
	if (!holder || !str)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(holder) + ft_strlen(str) + 1));
	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	if (holder)
		while (holder[++i])
			s[i] = holder[i];
	while (str[j])
		s[i++] = str[j++];
	s[i] = '\0';
	free(holder);
	return (s);
}

char	*get_holded_line(char *holder)
{
	int		i;
	char	*str;

	i = 0;
	if (!holder[i])
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		str[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
	{
		str[i] = holder[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*holder_refresher(char *tutucu)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (tutucu[i] && tutucu[i] != '\n')
		i++;
	if (!tutucu[i])
	{
		free(tutucu);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(tutucu) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (tutucu[i])
		str[j++] = tutucu[i++];
	str[j] = '\0';
	free(tutucu);
	return (str);
}
