/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:20:51 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/11 17:25:59 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_is_numbre(char *line)
{
	int len;
	int i;

	i = -1;
	if (line[0] == '#' && line[1] != '#')
		return (0);
	len = ft_strlen(line);
	while (len <= 10 && line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	if (ft_atoi(line) <= 0 || len > 10)
		return (0);
	return (1);
}

static int	between(int val, int nb1, int nb2)
{
	if (val >= nb1 && val <= nb2)
		return (1);
	return (0);
}

int			is_cord(char *nbr)
{
	int i;

	i = -1;
	while (nbr[++i])
	{
		if (i == 0 && (nbr[i] == '-' || nbr[i] == '+'))
			i++;
		if (!ft_isdigit(nbr[i]))
			return (0);
	}
	return (1);
}

static int	get_line_type(char *line, t_map **tmp, int *flag)
{
	int i;

	i = 0;
	if ((*tmp) && line[0] == '#' && line[1] != '#')
		return (((*tmp)->type = 5) ? 1 : 0);
	if (ft_strnequ(line, "##", 2) &&
	!ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
		return (((*tmp)->type = 4) ? 1 : 0);
	if (!(*flag & ANTS))
	{
		if (!ft_is_numbre(line))
			return (0);
		*flag |= ANTS;
		return (((*tmp)->type = 1) ? 1 : 0);
	}
	if (ft_strnequ(line, "##", 2))
		return (check_cmd(line, tmp, flag));
	if (!(*flag & START_LINKS) && check_room(line))
		return (((*tmp)->type = 2) ? 1 : 0);
	*flag |= START_LINKS;
	while ((line = ft_strchr(line, '-')) && line++)
		i++;
	if (!((*tmp)->type = (i == 1) * 3))
		return (0);
	return (1);
}

int			stock_map(t_map **map)
{
	char	*line;
	int		flag;

	flag = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!get_line_type(line, map, &flag))
			return (ft_free_data(&line));
		if (!between((*map)->type, 1, 7))
			return (ft_free_data(&line));
		if (!(*map)->data)
			(*map)->data = ft_strdup(line);
		if (!((*map)->next = (t_map *)ft_memalloc(sizeof(t_map))))
			return (ft_free_data(&line));
		*map = (*map)->next;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
