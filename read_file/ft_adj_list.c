/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adj_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:20:23 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/10 15:40:31 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	init(t_queue *tmp_1, t_queue *tmp_2)
{
	tmp_1->node_parent = -1;
	tmp_1->next = NULL;
	tmp_2->node_parent = -1;
	tmp_2->next = NULL;
}

int			ft_create_adj(t_lem_in **lst, int nbrooms)
{
	if (!((*lst)->adlist = (t_queue **)malloc(sizeof(t_queue *) * nbrooms)))
		return (0);
	ft_memset((void *)(*lst)->adlist, '\0', sizeof(t_queue *) * nbrooms);
	if (!((*lst)->g = (t_group **)malloc(sizeof(t_group *) * 2)))
		return (0);
	ft_memset((void *)(*lst)->g, '\0', sizeof(t_group*) * 2);
	return (1);
}

int			ft_add_node(t_lem_in **adj_list, int room_1, int room_2)
{
	t_queue		*tmp_1;
	t_queue		*tmp_2;
	t_queue		**lst;

	lst = (*adj_list)->adlist;
	if (!(tmp_1 = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	if (!(tmp_2 = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	tmp_1->node = room_1;
	tmp_2->node = room_2;
	init(tmp_1, tmp_2);
	if (lst[room_1])
		tmp_2->next = lst[room_1];
	lst[room_1] = tmp_2;
	if (lst[room_2])
		tmp_1->next = lst[room_2];
	lst[room_2] = tmp_1;
	return (1);
}
