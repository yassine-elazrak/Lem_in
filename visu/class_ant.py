#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    class_ant.py                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 16:10:01 by mobouzar          #+#    #+#              #
#    Updated: 2020/02/04 16:10:01 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import numpy as np

class Ant():

    def __init__(self, number, path=None,
                journey=None, color=""):
        self.number = number
        self.path = path
        self.journey = journey
        self.color = color

    def set_path(self, field):
        self.path = []
        started = False
        self.path.append(field.start)
        for ins in field.moves:
            for move in ins:
                if (move[0] == str(self.number)):
                    self.path.append(move[1])
                    started = True
            if not started:
                self.path.append(field.start)
    
    def set_location(self, field, pos):
        location = pos[field.start]
        self.current_location = location
    
    def set_journey(self, pos, num_steps):
        location_list = []
        for i in range(len(self.path)):
            if i != 0:
                start_pos = pos[self.path[i - 1]]
                end_pos = pos[self.path[i]]
                x = np.linspace(start_pos[0], end_pos[0], num=num_steps)
                y = np.linspace(start_pos[1], end_pos[1], num=num_steps)
                location_list.extend(list(zip(x, y)))
            i += 1
        self.journey = location_list
    