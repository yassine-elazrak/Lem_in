#!/usr/bin/env python
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    class_field.py                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 19:54:28 by mobouzar          #+#    #+#              #
#    Updated: 2020/01/14 19:54:29 by mobouzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class ant_field:

	def __init__(self):
		self.ants   		= None
		self.start  		= None
		self.end    		= None
		self.moves_nb  		= None
		self.nodes  		= []
		self.used_nodes  	= []
		self.pos    		= {}
		self.links  		= []
		self.used_links		= []
		self.moves  		= []
