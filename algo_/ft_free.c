/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 12:00:08 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/09 12:02:09 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			ft_free_tab(char ***tab)
{
	int			i;
	char		**str;

	i = 0;
	if (!(*tab))
		return ;
	str = *tab;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_memdel((void **)tab);
}

static void		ft_free_init_(t_print **init)
{
	if ((*init) && (*init)->next)
		ft_free_init_(&(*init)->next);
	ft_strdel(&(*init)->name);
	ft_memdel((void **)init);
}

void			ft_free_init(t_print ***init, int j)
{
	t_lem_in	*p;
	int			i;

	if ((*init))
	{
		p = getset(0);
		i = 0;
		while (i < j && (*init)[i])
		{
			ft_free_init_(&(*init)[i]);
			i++;
		}
		ft_memdel((void **)init);
	}
}

void			ft_free_queue__(t_queue **lst)
{
	if ((*lst) && (*lst)->next)
		ft_free_queue__(&(*lst)->next);
	ft_memdel((void **)lst);
}
