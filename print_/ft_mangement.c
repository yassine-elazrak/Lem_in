/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mangement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:20:35 by yelazrak          #+#    #+#             */
/*   Updated: 2020/02/11 20:45:38 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void				ft_get_path_22(t_lem_in *lst, int **path, int *node)
{
	int				i;
	int				min;

	if (lst->end == lst->start || (*path) == NULL)
		return ;
	i = lst->end;
	min = lst->start;
	while (i != min)
	{
		if ((*path)[i] != lst->start && (*path)[i] != lst->end)
			node[(*path)[i]] = 1;
		i = (*path)[i];
	}
}

static void				ft_init_bufer(t_lem_in *l,
int **node_visit, int **node_visit22)
{
	if (!((*node_visit) = (int *)malloc(sizeof(int) * ((l->nbrooms)))))
		return ;
	if (!(*node_visit22 = (int *)malloc(sizeof(int) * ((l->nbrooms)))))
		return ;
	ft_memset((void *)(*node_visit), 0, sizeof(int) * l->nbrooms);
	ft_memset((void *)(*node_visit22), 0, sizeof(int) * l->nbrooms);
}

static void				ft_free_buffer(int **node_visit,
int **node_visit22, int **path)
{
	ft_memdel((void **)path);
	ft_memdel((void **)node_visit);
	ft_memdel((void **)node_visit22);
}

static int				ft_get_paths(t_lem_in *l, int *path)
{
	int				*node_visit;
	int				*node_visit22;

	ft_init_bufer(l, &node_visit, &node_visit22);
	while ((path = ft_bfs(l, 0, node_visit, 0)))
	{
		if (path && path[l->end] == l->start)
		{
			ft_free_buffer(&node_visit, &node_visit22, &path);
			return (1);
		}
		ft_get_path_(&path, 0, node_visit, &node_visit22);
		while ((path = ft_bfs(l, 1, node_visit22, 1)))
		{
			ft_get_path_22(l, &path, node_visit22);
			ft_add_group(&(l->g), path, 1);
			ft_memdel((void **)&path);
		}
		ft_get_best_grp(&(l->g), l->nbants);
		if (getset(0)->quit == 1)
			break ;
	}
	ft_free_buffer(&node_visit, &node_visit22, &path);
	return (0);
}

void					ft_mangement_instructoin(t_lem_in *l,
t_map *head)
{
	int						*path;

	path = NULL;
	if (ft_get_paths(l, path))
	{
		print_data(head);
		while (l->nbr_ant_start++ < l->nbants)
			ft_printf("L%d-%s ", (l->nbr_ant_start), l->rooms[l->end]);
		ft_putchar('\n');
	}
	else
	{
		if (!(l->g[0]))
			ft_putendl("not path");
		else
		{
			print_data(head);
			ft_print_instructoin();
		}
	}
}
