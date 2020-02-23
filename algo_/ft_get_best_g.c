/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_best_g.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:49:23 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/07 18:32:47 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void				ft_push_queue(t_queue **lst, int node)
{
	if (!(*lst))
	{
		if (!((*lst) = (t_queue *)malloc(sizeof(t_queue))))
			return ;
		(*lst)->node = node;
		(*lst)->flow = 0;
		(*lst)->next = NULL;
	}
	else
	{
		if (!((*lst)->next = (t_queue *)malloc(sizeof(t_queue))))
			return ;
		(*lst)->next->node = node;
		(*lst)->next->flow = 0;
		(*lst)->next->next = NULL;
		(*lst) = (*lst)->next;
	}
}

int					ft_count_group(t_group *lst, int *i)
{
	int				len;

	len = 0;
	(*i) = 0;
	while (lst)
	{
		len += ft_path_len(lst->grp);
		lst = lst->next;
		(*i)++;
	}
	return (len);
}

static void			ft_free_group(t_group **lst)
{
	if ((*lst) && (*lst)->next)
		ft_free_group(&(*lst)->next);
	ft_memdel((void **)&(*lst)->grp);
	ft_memdel((void **)lst);
}

int					ft_get_best_scor(t_group **lst, int ants)
{
	t_group			*tmp;
	int				scor;
	int				j;
	int				k;
	int				g1;

	scor = -1;
	j = 0;
	k = 0;
	tmp = *lst;
	if ((*lst)->scor != -1)
		return ((*lst)->scor);
	while (tmp && ++j)
	{
		k += ft_path_len(tmp->grp);
		g1 = ft_ceil(k + ants, j);
		if (g1 > scor && scor != -1)
		{
			(*lst)->scor = scor;
			return (scor);
		}
		scor = g1;
		tmp = tmp->next;
	}
	return (scor);
}

void				ft_get_best_grp(t_group ***lst, int nbants)
{
	int				g1;
	int				g2;

	if (!(*lst)[1] || !(*lst[0]))
	{
		(*lst)[0] = (*lst)[1];
		(*lst)[1] = NULL;
		return ;
	}
	g1 = ft_get_best_scor(&(*lst)[0], nbants);
	g2 = ft_get_best_scor(&(*lst)[1], nbants);
	if (g1 < g2)
		getset(0)->quit = 1;
	if (g1 > g2)
	{
		ft_free_group(&((*lst)[0]));
		(*lst)[0] = (*lst)[1];
		(*lst)[1] = NULL;
	}
	else
	{
		ft_free_group(&((*lst)[1]));
		(*lst)[1] = NULL;
	}
}
