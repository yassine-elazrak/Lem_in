#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    main.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 16:08:24 by mobouzar          #+#    #+#              #
#    Updated: 2020/02/04 16:08:25 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import matplotlib.pyplot as plt
import matplotlib.animation as matAni
import networkx as nx
import numpy as np
import sys
import re

from parser import parser
from class_ant import Ant
from path_colors import set_paths_colors
from draw import draw_nodes, get_settings, draw_ant, usage
from events import *

import warnings
warnings.filterwarnings("ignore", category=UserWarning)

def on_key(event):
    global settings
    global anim_running
    if (event.key == "p"):
        anim_running = play_pause(ani, anim_running)
    elif (event.key == 'z' or event.key == 'x'):
        up_node_size(event.key, settings)
    elif (event.key == 'c' or event.key == 'v'):
        up_ant_size(event.key, settings)

def animation(frame, data, fig, ant_squad, settings):
    fig.clear()
    
    fig.canvas.mpl_connect("key_press_event", on_key)
    nx.draw_networkx_edges(data['g'], data['pos'], edgelist=data['field'].links, edge_color='#101010', width=2.0)

    for i, path in enumerate(data['field'].used_links):
        nx.draw_networkx_edges(data['g'], data['pos'], edgelist=path, edge_color=settings['used'][i], width=2.0)
    draw_nodes(data, settings)

    for ant in ant_squad:
        if frame < len(ant.journey):
            draw_ant(ant.journey[frame], ant.color, settings)
    
    nx.draw_networkx_labels(
        data['g'],
        data['pos'],
        font_size = 8,
        labels = settings['labels'],
        font_family = 'sans-serif',
        font_color = settings['text_color'])

    fig.set_facecolor(settings['background_color'])
    plt.axis('off')

def make_graph(field):
    g = nx.Graph()
    g.add_nodes_from(field.nodes)
    g.add_edges_from(field.links)
    return (g)

def create_data():
    data = {}
    data['field'] = parser()
    data['g'] = make_graph(data['field'])
    data['pos'] = nx.spring_layout(data['g'])
    return (data)

def make_squad(data, settings):
    ant_list = []
    for nb in range(1, (int(data['field'].ants) + 1)):
        ant = Ant(nb)
        ant.set_path(data['field'])
        ant.set_location(data['field'], data['pos'])
        ant.set_journey(data['pos'], settings['steps_between_nodes'])
        ant.color = settings['ant_colors_list']
        ant_list.append(ant)
    return (ant_list)

try:
    usage()
    data = create_data()
    settings = get_settings(data['field'])
    ant_squad = make_squad(data, settings)
    set_paths_colors(data['field'], ant_squad)

    fig = plt.figure(figsize=(settings["window_size"]))
    anim_running = True
    ani = matAni.FuncAnimation(
        fig,
        animation,
        frames = data['field'].moves_nb * settings['steps_between_nodes'],
        fargs = (data, fig, ant_squad, settings),
        interval = settings['interval'],
        repeat = settings['repeat'],
        blit = 0)
    plt.show()
except:
    print("ERROR")
    quit()
