#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    path_colors.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 16:09:20 by mobouzar          #+#    #+#              #
#    Updated: 2020/02/04 16:09:22 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def get_ants(field):
    ants = []
    for move in field.moves[0]:
        ants.append(move[0])
    return (ants)

def get_path(ant_squad, ants):
    path = []
    for ant in ants:
        path.append(ant_squad[int(ant) - 1].path)
    return (path)

def get_used_nodes(paths):
    used_nodes = []
    for path in paths:
        used_nodes.append(path[1:-1])
    return (used_nodes)

def get_used_links(paths):
	links = []
	all_links = []
	for path in paths:
		for node in zip(path, path[1:]):
			link = [node[0], node[1]]
			links.append(link)
		all_links.append(links)
		links = []
	return (all_links)

def remove_links_in_original_list(field):
	for path in field.used_links:
		for link in path:
			if link in field.links:
				field.links.remove(link)
			link = list(reversed(link))
			if link in field.links:
				field.links.remove(link)

def remove_nodes_in_original_list(field):
	for path in field.used_nodes:
		for node in path:
			if node in field.nodes:
				field.nodes.remove(node)

def set_paths_colors(field, ant_squad):
    ants = get_ants(field)
    paths = get_path(ant_squad, ants)
    field.used_nodes = get_used_nodes(paths)
    field.used_links = get_used_links(paths)
    remove_links_in_original_list(field)
    remove_nodes_in_original_list(field)

    

