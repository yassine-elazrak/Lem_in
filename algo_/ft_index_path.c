/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:19:38 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/07 09:34:07 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_lem_in			*getset(t_lem_in *l)
{
	static t_lem_in	*g;

	if (l)
		g = l;
	return (g);
}

static int			ft_index_path_cap(t_lem_in *lst,
int end_room, int strat, int index)
{
	t_queue			*q;
	int				i;

	i = (index == 0 ? 1 : 0);
	q = lst->adlist[strat];
	while (q)
	{
		if (q->node == end_room)
		{
			if (q->flow == i)
			{
				q->flow = -2;
				return (1);
			}
		}
		q = q->next;
	}
	return (0);
}

static void			ft_index_path(t_lem_in *lem,
int end_room, int strat, int index)
{
	t_queue			*q;

	q = lem->adlist[strat];
	while (q)
	{
		if (q->node == end_room)
		{
			if (ft_index_path_cap(lem, strat, end_room, index))
				q->flow = -2;
			else
				q->flow = (index == 0 ? 1 : 0);
		}
		q = q->next;
	}
}

void				ft_get_path_(int **path, int index, int *node, int **v)
{
	t_lem_in		*lst;
	int				i;
	int				min;

	lst = getset(0);
	if (lst->end == lst->start || (*path) == NULL)
		return ;
	i = lst->end;
	min = lst->start;
	while (i != min)
	{
		if ((*path)[i] != lst->start && (*path)[i] != lst->end)
			node[(*path)[i]] = 1;
		lst->adlist[i]->node_parent = (*path)[i];
		ft_index_path(lst, i, (*path)[i], index);
		i = (*path)[i];
	}
	ft_memdel((void **)path);
	ft_memset((void *)(*v), 0, sizeof(int) * lst->nbrooms);
}
