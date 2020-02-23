/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 04:05:38 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/11 17:26:14 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_free_split(char **split, int ret)
{
	int i;

	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	ft_memdel((void *)&split);
	return (ret);
}

static int	ft_free_rooms(t_room **room, int ret)
{
	ft_free_room(room);
	return (ret);
}

int			check_link(t_lem_in **l, char *link)
{
	char	**split;
	int		room1;
	int		room2;
	int		i;

	i = 0;
	room1 = -1;
	room2 = -1;
	if (!(split = ft_split_format(link, '-')))
		return (0);
	while (split[i])
		i += 1;
	if (i != 2 || ((*l)->start == -1 || (*l)->end == -1))
		return (ft_free_split(split, 0));
	if ((room1 = ft_contains(*l, split[0])) != -1 &&
		(room2 = ft_contains(*l, split[1])) != -1)
	{
		if (!ft_add_node(l, room1, room2))
			return (ft_free_split(split, 0));
	}
	else
		return (ft_free_split(split, 0));
	return (ft_free_split(split, 1));
}

static int	create_graph(t_lem_in **l, t_room *room, char *link)
{
	if ((*l)->ret == 0 && (*l)->start >= 0 && (*l)->end >= 0 && ((*l)->ret = 1))
		if (!create_array(*l, room) || !ft_create_adj(l, (*l)->nbrooms))
			return (0);
	if (!check_link(l, link))
		return (0);
	return (1);
}

int			read_data(t_lem_in **l, t_map **map)
{
	t_room	*room;
	t_room	*head;

	room = (t_room *)ft_memalloc(sizeof(t_room));
	head = room;
	if (!room || !stock_map(&map[1]))
		return (ft_free_rooms(&head, 0));
	while ((*map) && (*map)->next)
	{
		if ((*map)->type == 1)
			(*l)->nbants = ft_atoi((*map)->data);
		else if ((*map)->type == 2 || (*map)->type == 6 || (*map)->type == 7)
		{
			if (!stock_room(l, *map, &room))
				return (ft_free_rooms(&head, 0));
		}
		else if ((*map)->type == 3)
			if (!create_graph(l, head, (*map)->data))
				return (ft_free_rooms(&head, 0));
		*map = (*map)->next;
	}
	return (ft_free_rooms(&head, 1));
}
