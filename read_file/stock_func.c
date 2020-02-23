/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:56:52 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/11 15:05:51 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_free_data(char **line)
{
	ft_strdel(line);
	return (0);
}

static int	ft_free_split(char **split, int ret)
{
	int i;

	i = -1;
	while (split[++i])
		ft_strdel(&split[i]);
	ft_memdel((void *)&split);
	return (ret);
}

int			check_room(char *line)
{
	char	**split;
	int		i;

	i = 0;
	if (line[0] == 'L' || line[0] == '#')
		return (0);
	if (!(split = ft_split_format(line, ' ')))
		return (0);
	while (split[i] != NULL)
		i++;
	if (i != 3)
		return (ft_free_split(split, 0));
	if (!is_cord(split[1]) || !is_cord(split[2]))
		return (ft_free_split(split, 0));
	return (ft_free_split(split, 1));
}

int			check_cmd(char *line, t_map **tmp, int *flag)
{
	char	*line2;
	int		start;

	if ((start = ft_strequ(line, "##start")) || ft_strequ(line, "##end"))
	{
		if (*flag & (start ? START_TOKEN : END_TOKEN))
			return (0);
		if (get_next_line(0, &line2) == 1)
		{
			(*tmp)->data = ft_strdup(line);
			(*tmp)->type = 4;
			(*tmp)->next = (t_map *)ft_memalloc(sizeof(t_map));
			if (!check_room(line2) || !((*tmp)->next))
				return (ft_free_data(&line2));
			*tmp = (*tmp)->next;
			(*tmp)->data = ft_strdup(line2);
			(*tmp)->type = start ? 6 : 7;
			*flag |= start ? START_TOKEN : END_TOKEN;
			ft_strdel(&line2);
		}
	}
	return (1);
}

int			stock_room(t_lem_in **l, t_map *map, t_room **r)
{
	char	**split;

	if (!(split = ft_split_format(map->data, ' ')))
		return (0);
	(*r)->name = ft_strdup(split[0]);
	(*r)->cords.x = ft_atoi(split[1]);
	(*r)->cords.y = ft_atoi(split[2]);
	if (map->type == 6)
		(*l)->start = (*l)->nbrooms;
	else if (map->type == 7)
		(*l)->end = (*l)->nbrooms;
	if (!((*r)->next = (t_room *)ft_memalloc(sizeof(t_room))))
		return (ft_free_split(split, 0));
	(*r) = (*r)->next;
	(*l)->nbrooms += 1;
	return (ft_free_split(split, 1));
}
