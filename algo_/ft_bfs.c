/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 10:47:42 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/10 16:48:25 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static t_queue			*ft_front_queue(t_queue **q)
{
	t_queue				*tmp;

	tmp = NULL;
	tmp = *q;
	tmp = *q;
	if ((*q)->next)
		(*q) = (*q)->next;
	else
		(*q) = NULL;
	return (tmp);
}

static void				ft_init_(t_bfs **bfs,
int **vist, int nbroom, int strat)
{
	(*bfs) = NULL;
	if (!((*bfs) = (t_bfs *)malloc(sizeof(t_bfs))))
		return ;
	ft_memset((*bfs), '\0', sizeof(t_bfs));
	if (!((*vist) = (int *)malloc(sizeof(int) * (nbroom))))
		return ;
	ft_memset((*vist), -1, sizeof(int) * (nbroom));
	ft_push_queue(&(*bfs)->q, strat);
	(*vist)[strat] = 0;
	(*bfs)->last = (*bfs)->q;
}

static int				ft_condition(t_bfs *lst,
t_queue *queue, t_queue *tmp, int *vist)
{
	t_lem_in			*lem;
	int					*node;

	lem = getset(0);
	node = lst->ptr_node;
	if (vist[queue->node] == -1 &&
	queue->flow == lst->flow &&
		lst->index_flow == 1 && node[queue->node] == 0)
		return (1);
	else if ((vist[queue->node] == -1 &&
	queue->flow == lst->flow &&
	lst->index_flow == 0) &&
	(node[tmp->node] == 0 || (node[tmp->node] == 1 &&
	((lem->adlist[vist[tmp->node]]->node_parent != tmp->node &&
	node[vist[tmp->node]] == 0 && node[tmp->node] == 1 &&
lem->adlist[tmp->node]->node_parent == queue->node &&
tmp->flow == lst->flow) ||
(node[vist[tmp->node]] == 1 &&
lem->adlist[vist[tmp->node]]->node_parent == tmp->node)))))
		return (1);
	return (0);
}

static int				ft_visit_child(t_bfs *lst,
t_queue *tmp, int *vist, int *node)
{
	t_queue				*queue;
	t_lem_in			*lem;

	lem = getset(0);
	lst->ptr_node = node;
	queue = lem->adlist[tmp->node];
	while (queue)
	{
		if (queue->node == lem->end && queue->flow == lst->flow)
		{
			vist[queue->node] = tmp->node;
			return (1);
		}
		if (ft_condition(lst, queue, tmp, vist))
		{
			vist[queue->node] = tmp->node;
			ft_push_queue(&lst->last, queue->node);
			if (!(lst->q))
				lst->q = lst->last;
		}
		queue = queue->next;
	}
	return (0);
}

int						*ft_bfs(t_lem_in *lem, int c, int *node, int y)
{
	t_bfs				*lst;
	t_queue				*tmp;
	int					*vist;

	ft_init_(&lst, &vist, lem->nbrooms, lem->start);
	lst->index_flow = y;
	lst->flow = c;
	while (lst->q)
	{
		tmp = ft_front_queue(&lst->q);
		if (ft_visit_child(lst, tmp, vist, node))
		{
			ft_memdel((void **)&tmp);
			ft_free_queue__(&lst->q);
			ft_memdel((void **)&lst);
			return (vist);
		}
		ft_memdel((void **)&tmp);
	}
	ft_free_queue__(&lst->q);
	ft_memdel((void **)&lst);
	ft_memdel((void **)&vist);
	return (0);
}
