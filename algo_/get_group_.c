/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_group_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:28:26 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/07 18:40:32 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static t_group		*ft_get_group(char *group)
{
	t_group			*g;

	if (!(g = (t_group *)malloc(sizeof(t_group))))
		return (NULL);
	ft_memset((void *)g, '\0', sizeof(t_group));
	g->grp = ft_strdup(group);
	g->len_g = -1;
	g->scor = -1;
	g->next = NULL;
	return (g);
}

static char			*ft_convert_int_char(int *visit, int max, int min)
{
	int				i;
	char			*str;

	i = max;
	str = ft_itoa(max);
	while (i != min)
	{
		str = ft_strjoin_free(ft_strdup("-"), str);
		str = ft_strjoin_free(ft_itoa(visit[i]), str);
		i = visit[i];
	}
	return (str);
}

static int			ft_check_path(char *str, char *g)
{
	char			**room;
	char			*tmp;
	int				i;

	i = 0;
	tmp = NULL;
	room = ft_strsplit(g, '-');
	while (room[i])
	{
		tmp = ft_strjoin("-", room[i]);
		tmp = ft_strjoin_free(tmp, ft_strdup("-"));
		if (strstr(str, tmp))
		{
			ft_strdel(&tmp);
			ft_free_tab(&room);
			return (1);
		}
		i++;
		ft_strdel(&tmp);
	}
	ft_free_tab(&room);
	return (0);
}

static int			ft_add_path(t_group **lst,
char *group, int i)
{
	t_group			*tmp;
	int				a;

	tmp = lst[i];
	a = 0;
	while (tmp->next)
	{
		if (ft_check_path(tmp->grp, group))
			a = 1;
		tmp = tmp->next;
	}
	if (ft_check_path(tmp->grp, group))
		a = 1;
	if (a == 0)
	{
		if (!lst[i])
			lst[i] = ft_get_group(group);
		else
			tmp->next = ft_get_group(group);
		return (1);
	}
	return (0);
}

void				ft_add_group(t_group ***lst,
int *visit, int i)
{
	t_lem_in		*l;
	t_group			**tmp;
	char			*group;

	tmp = *lst;
	l = getset(0);
	group = ft_convert_int_char(visit, l->end, l->start);
	if (!tmp[i])
	{
		tmp[i] = ft_get_group(group);
		ft_strdel(&group);
		return ;
	}
	ft_add_path(*lst, group, i);
	ft_strdel(&group);
}
