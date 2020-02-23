/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:49:39 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/11 20:42:09 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

# define ANTS 01
# define START_ROOMS 2
# define START_LINKS 4
# define START_TOKEN 8
# define END_TOKEN 16

typedef struct		s_print
{
	char			*name;
	int				scor;
	int				bant;
	int				len_path;
	struct s_print	*next;
}					t_print;

typedef struct		s_group
{
	char			*grp;
	int				len_g;
	int				scor;
	struct s_group	*next;
}					t_group;

typedef struct		s_queue
{
	int				node;
	int				flow;
	int				node_parent;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_bfs
{
	t_queue			*q;
	t_queue			*last;
	int				*ptr_node;
	int				index_flow;
	int				flow;
}					t_bfs;

typedef struct		s_map
{
	char			*data;
	int				type;
	struct s_map	*next;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_room
{
	t_point			cords;
	char			*name;
	struct s_room	*next;
}					t_room;

typedef struct		s_lem_in
{
	t_queue			**adlist;
	t_group			**g;
	char			**rooms;
	int				ret;
	int				nbants;
	int				nbrooms;
	int				start;
	int				end;
	int				nbr_ant_start;
	int				nbr_ant_end;
	int				quit;
	int				len;
	int				nbr;
}					t_lem_in;

int					get_nbants(t_lem_in *l, char *line);
int					read_data(t_lem_in **l, t_map **map);
int					check_room(char *line);
int					get_rooms(t_lem_in *l, t_room **r,
t_map **m, char *line);
int					get_links(t_lem_in **l, char *line);
int					ft_create_adj(t_lem_in **lst, int nbrooms);
int					create_array(t_lem_in *l, t_room *room);
int					ft_contains(t_lem_in *l, char *element);
int					*ft_bfs(t_lem_in *lem, int c, int *node, int y);
int					ft_path_len(char *path);
t_print				**ft_chang_path(t_lem_in *l, int lenght);
t_lem_in			*getset(t_lem_in *l);
void				ft_mangement_instructoin(t_lem_in *l, t_map *head);
void				ft_free_tab(char ***tab);
void				ft_free_queue(t_queue **lst);
void				ft_add_group(t_group ***lst, int *group, int i);
int					ft_add_node(t_lem_in **adj_list, int room_1, int room_2);
void				ft_get_best_grp(t_group ***lst, int nbants);
void				ft_print_instructoin();
void				ft_print_adj(t_lem_in *adj);
void				ft_get_path_(int **path,
int index, int *node, int **v);
void				ft_free_init(t_print ***init, int j);
void				ft_free_queue__(t_queue **lst);
void				ft_push_queue(t_queue **lst, int node);
void				ft_struct_lem_in(t_lem_in **l, t_map **map);
void				ft_free_room(t_room **g);
void				ft_free_map(t_map **map);

int					stock_map(t_map **map);
void				print_data(t_map *data);
int					is_cord(char *nbr);
int					ft_free_data(char **line);
int					check_room(char *line);
int					check_cmd(char *line, t_map **tmp, int *flag);
int					stock_room(t_lem_in **l, t_map *map, t_room **r);

#endif
