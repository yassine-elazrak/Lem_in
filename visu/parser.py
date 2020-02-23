#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parser.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 19:35:03 by mobouzar          #+#    #+#              #
#    Updated: 2020/01/14 19:35:11 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from class_field import ant_field
import numpy as np
import sys
import re

def check_status(status, field, line):
	if status == None:
		return status
	elif status == 'start':
		field.start = line.split(' ')[0]
	elif status == 'end':
		field.end = line.split(' ')[0]
	elif status == 'comment':
		pass
	status = None
	return (status)

def get_room(field, line):
	line_split = line.split(' ')
	name = line_split[0]
	pos_x = line_split[1]
	pos_y = line_split[2]
	field.nodes.append(name)
	for node in field.nodes:
		field.pos[node] = np.array([int(pos_x), int(pos_y)])

def get_link(field, line):
	line_split = line.strip().split('-')
	field.links.append(line_split)

def	get_move(field, line):
	moves_final = []
	line_split =line.strip().split(' ')
	for move in line_split:
		array = []
		tmp = move.split('-')
		array.append(tmp[0].strip('L'))
		array.append(tmp[1])
		moves_final.append(array)
	field.moves.append(moves_final)

def parser():
	field = ant_field()
	status = None
	room_nbr = 0

	for line in sys.stdin:
		status = check_status(status, field, line)
		if (re.compile(r"^\d+$").search(line)):
			field.ants = int(line)
		elif (re.compile(r"^#{2}(start)").search(line)):
			status = "start"
		elif (re.compile(r"^#{2}(end)").search(line)):
			status = "end"
		elif (re.compile(r"^#").search(line)):
			status = "comment"
		elif (re.compile(r"^([\d\w]+) \d+ \d+\n$").search(line)):
			room_nbr += 1
			if (room_nbr > 1000):
				print("The map you are trying to run is really big!\nIt will take lot of time to launch it")
				quit()
			get_room(field, line)
		elif (line[0] != 'L' and re.compile(r"^([\d\w]+)-([\d\w]+)\n$").search(line)):
			get_link(field, line)
		elif (re.compile(r"^L([\d]+)-([\d\w]+)").search(line)):
			get_move(field, line)
		elif (re.compile(r"ERROR").search(line)):
			quit()
	field.moves_nb = len(field.moves)
	return (field)
