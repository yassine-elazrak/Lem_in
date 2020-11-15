/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructoin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:50:05 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/10 16:30:21 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		ft_instrcutoin(t_lem_in *l, t_print **q, t_print **m)
{
	if ((*q) && (*q)->bant != 0)
	{
		ft_printf("L%d-%s ", (*q)->bant, (*m)->name);
		(*m)->bant = (*q)->bant;
		if (!ft_strcmp((*m)->name, l->rooms[l->end]))
			l->nbr_ant_end++;
		(*q)->bant = 0;
	}
	(*m) = (*q);
	(*q) = (*q)->next;
}

static void		ft_print_(t_lem_in *l, t_print ***init, int path)
{
	t_print		**g;
	t_print		*q;
	t_print		*m;
	int			i;

	g = *init;
	i = -1;
	while (++i < path)
	{
		q = g[i]->next->next;
		m = g[i]->next;
		while (q)
		{
			ft_instrcutoin(l, &q, &m);
		}
		if (l->nbr_ant_start < l->nbants && g[i]->scor > 0)
		{
			l->nbr_ant_start++;
			ft_printf("L%d-%s ", (l->nbr_ant_start), m->name);
			m->bant = l->nbr_ant_start;
			g[i]->scor--;
		}
	}
	ft_putchar_fd('\n', 1);
}

static int		ft_get_best_path_(t_group **lst, int ants)
{
	t_group		*tmp;
	int			scor;
	int			j;
	int			g1;
	int			k;

	scor = -1;
	j = 1;
	k = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp->len_g = ft_path_len(tmp->grp);
		k += tmp->len_g;
		g1 = ft_ceil(k + ants, j);
		if (g1 >= scor && scor != -1)
			return (j - 1);
		scor = g1;
		getset(0)->len = tmp->len_g;
		j++;
		tmp = tmp->next;
	}
	return (j - 1);
}

void			ft_print_instructoin(void)
{
	t_group		*tmp;
	t_print		**init;
	t_lem_in	*lem;
	int			i;

	lem = getset(0);
	tmp = lem->g[0];
	i = ft_get_best_path_(&tmp, lem->nbants);
	if (!(init = ft_chang_path(lem, i)))
		return ;
	while (lem->nbr_ant_end < lem->nbants)
		ft_print_(lem, &init, i);
	ft_free_init(&init, i);
}
