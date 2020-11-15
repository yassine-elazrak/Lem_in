/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 09:45:53 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/10 16:30:43 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				ft_path_len(char *path)
{
	int			i;
	int			len;

	i = -1;
	len = 0;
	while (path[++i])
	{
		if (path[i] == '-')
			len++;
	}
	return (len > 0 ? len - 1 : len);
}

static t_print	*ft_get_(char *tmp, char **tab_name)
{
	t_print		*lst;

	if (!(lst = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	ft_memset((void *)lst, 0, sizeof(t_print));
	lst->name = ft_strdup(tab_name[ft_atoi(tmp)]);
	lst->bant = 0;
	lst->next = NULL;
	return (lst);
}

static t_print	*ft_get_node_name(char *str, char **tab_name)
{
	t_print		*init;
	t_print		*lst;
	char		**tmp;
	int			i;

	init = NULL;
	i = ft_path_len(str) + 1;
	if (!(tmp = ft_strsplit(str, '-')))
		return (NULL);
	lst = ft_get_(tmp[0], tab_name);
	lst->len_path = ft_path_len(str);
	init = lst;
	while (i > 0)
	{
		init->next = ft_get_(tmp[i], tab_name);
		init = init->next;
		init->next = NULL;
		i--;
	}
	ft_free_tab(&tmp);
	return (lst);
}

static t_print	**ft_get_ants_start(t_print ***init, t_lem_in *l, int lenght)
{
	t_group		*g;
	int			i;
	int			j;
	int			k;

	i = -1;
	k = 0;
	g = l->g[0];
	l->nbr = l->nbants;
	while (g && ++i < lenght)
	{
		j = g->len_g;
		k += j;
		if (!((*init)[i] = ft_get_node_name(g->grp, l->rooms)))
			return (NULL);
		(*init)[i]->len_path = g->len_g;
		if (l->len - j >= 0)
			(*init)[i]->scor = l->len - j;
		if (l->len - j >= 0)
			l->nbr -= l->len - j;
		g = g->next;
	}
	return ((*init));
}

t_print			**ft_chang_path(t_lem_in *l, int lenght)
{
	t_print		**init;
	t_group		*g;
	int			i;

	g = l->g[0];
	if (!(init = (t_print **)malloc(sizeof(t_print *) * lenght)))
		return (NULL);
	ft_memset((void *)init, '\0', sizeof(t_print *) * lenght);
	if (!(init = ft_get_ants_start(&init, l, lenght)))
		return (NULL);
	while (l->nbr > 0)
	{
		i = -1;
		while (++i < lenght && l->nbr)
		{
			init[i]->scor++;
			l->nbr--;
		}
	}
	return (init);
}
