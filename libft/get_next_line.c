/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:51:01 by vrabaib           #+#    #+#             */
/*   Updated: 2019/03/08 14:21:21 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_list		*fd_archive(t_list **folder, int fd)
{
	t_list	*p;

	p = *folder;
	while (p)
	{
		if (p->content_size == (size_t)fd)
			return (p);
		else
			p = p->next;
	}
	p = ft_lstnew("\0", fd);
	ft_lstadd(folder, p);
	p = *folder;
	return (p);
}

static	int			get_correct_line(t_list *lst, char **str_p, int ret)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(lst->content);
	tmp = NULL;
	if (ret < BUFF_SIZE && !(len))
		return (0);
	while (((char *)(lst->content))[i] != '\n' && ((char *)(lst->content))[i])
		i++;
	if (!(*str_p = ft_strndup((lst->content), i)))
		return (0);
	if (i < len)
	{
		tmp = lst->content;
		lst->content = ft_strdup(lst->content + (i + 1));
		free(tmp);
	}
	else
		ft_strclr(lst->content);
	return (1);
}

int					get_next_line(const	int fd, char **line)
{
	int				ret;
	t_list			*file;
	char			buf[BUFF_SIZE + 1];
	static t_list	*folder;
	char			*tmp;

	tmp = NULL;
	if (fd < 0 || fd > MAX_FD || !line || BUFF_SIZE < 0 || \
			read(fd, buf, 0) < 0)
		return (-1);
	file = fd_archive(&folder, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin(file->content, buf)))
			return (-1);
		ft_strdel((char **)&(file->content));
		file->content = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (get_correct_line(file, line, ret));
}
