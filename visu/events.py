#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    events.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 16:09:39 by mobouzar          #+#    #+#              #
#    Updated: 2020/02/04 16:09:40 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def play_pause(ani, anim_running):
    if anim_running:
        ani.event_source.stop()
        anim_running = False
    else:
        ani.event_source.start()
        anim_running = True
    return anim_running

def up_node_size(key, settings):
    if (key == 'z'):
        settings['node_size'] += 30
    elif (key == 'x' and settings['node_size'] > 100):
        settings['node_size'] -= 30

def up_ant_size(key, settings):
    if (key == 'c'):
        settings['markersize'] += 5
    elif (key == 'v'):
        settings['markersize'] -= 5
