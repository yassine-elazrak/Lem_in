/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 22:26:58 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/10 20:01:36 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		ft_free_group(t_group **g)
{
	if ((*g) && (*g)->next)
		ft_free_group(&(*g)->next);
	ft_memdel((void **)&(*g)->grp);
	ft_memdel((void **)g);
}

void			ft_free_map(t_map **map)
{
	if ((*map) && (*map)->next)
		ft_free_map(&(*map)->next);
	ft_memdel((void **)&(*map)->data);
	ft_memdel((void **)map);
}

void			ft_free_room(t_room **room)
{
	if ((*room) && (*room)->next)
		ft_free_room(&(*room)->next);
	ft_memdel((void **)&(*room)->name);
	ft_memdel((void **)room);
}

void			ft_struct_lem_in(t_lem_in **l, t_map **map)
{
	int		i;

	i = -1;
	while ((*l)->adlist && ++i < (*l)->nbrooms)
		ft_free_queue__(&(*l)->adlist[i]);
	if ((*l)->adlist)
		ft_memdel((void **)&(*l)->adlist);
	if ((*l)->g && (*l)->g[0])
		ft_free_group(&(*l)->g[0]);
	if ((*l)->g)
		ft_memdel((void **)&(*l)->g);
	if ((*map))
		ft_free_map(map);
	ft_free_tab(&(*l)->rooms);
	ft_memdel((void **)&(*l));
}
