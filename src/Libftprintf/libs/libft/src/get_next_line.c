/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:40:14 by nparker           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/09 13:03:50 by vice-wra         ###   ########.fr       */
=======
/*   Updated: 2019/08/08 15:41:11 by vice-wra         ###   ########.fr       */
>>>>>>> 62dbaff45ce76e9563f2f0dabeb98542955b805f
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static int	read_line(int fd, char *str[fd])
{
	char	*temp;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	ret = 0;
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		temp = str[fd];
		if (!(str[fd] = ft_strjoin(str[fd], buff)))
			return (-1);
		free(temp);
	}
	return (ret);
}

static int	parse_str(int fd, char **line, char *str[fd], int flag)
{
	char	*temp;

	temp = str[fd];
	if (ft_strchr(temp, '\n'))
	{
		if (!(*line = ft_strsub(temp, 0, ft_strchr(temp, '\n') - temp)))
			return (-1);
	}
	else if (!(*line = ft_strdup(temp)))
		return (-1);
	if ((str[fd] = ft_strchr(str[fd], '\n')) == NULL)
		ft_bzero(str[fd], 0);
	else
	{
		str[fd]++;
		flag++;
	}
	if (str[fd] != NULL)
		if (!(str[fd] = ft_strdup(str[fd])))
			return (-1);
	free(temp);
	return (flag);
}

int			get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str[65536];
	int				flag;

	if (fd < 0 || fd >= 65536 || !line || BUFF_SIZE <= 0)
		return (-1);
	flag = 0;
	if (!str[fd])
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	ret = read_line(fd, str);
	if (ret == -1)
=======
static int			read_line(const int fd, char **str, char *buff, int read_fd)
{
	char			*temp;

	while ((read_fd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_fd] = '\0';
		if (!(temp = ft_strjoin(str[fd], buff)))
			return (-1);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (read_fd);
}

static int			create_line(char **str, char **line, int fd)
{
	char			*tmp;
	int				len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(str[fd] + len + 1)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*str[65536];
	char			buff[BUFF_SIZE + 1];
	int				read_fd;

	read_fd = 0;
	if (fd < 0 || read(fd, buff, 0) < 0 || line == NULL)
		return (-1);
	if (str[fd] == NULL)
	{
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	}
	if (read_line(fd, str, buff, read_fd) < 0)
		return (-1);
	if (read_fd < 0)
		return (-1);
	if (read_fd == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	if (create_line(str, line, fd) == -1)
>>>>>>> 62dbaff45ce76e9563f2f0dabeb98542955b805f
		return (-1);
	if (str[fd][0] != '\0')
		if ((flag = parse_str(fd, line, str, flag)) == -1)
			return (-1);
	if (str[fd] && !ret && flag == 0)
		return (0);
	return (1);
}
