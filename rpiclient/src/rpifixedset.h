/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpifixedset.h
 * Copyright (C) 2016 Vladimir Roncevic <elektron.ronca@gmail.com>
 * 
 * rpiclient-gtk is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * rpiclient-gtk is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __RPIFIXEDSET_H
#define __RPIFIXEDSET_H

#include "rpichannelset.h"

#define MAX_CHANNELS_SET					 8
#define START_X_POSITION_VERTICAL_BAR_SET	0
#define Y_POSITION_VERTICAL_BAR_SET		  0
#define START_X_POSITION_SCALE_SET		   70
#define Y_POSITION_SCALE_SET				 0
#define START_X_POSITION_SPINER_BUTTON_SET   0
#define Y_POSITION_SPINER_BUTTON_SET		 110
#define START_X_POSITION_ACTIVATE_GPIO_SET   0
#define Y_POSITION_ACTIVATE_GPIO_SET		 150
#define SHIFT_X_POSITION_SET				 120

typedef struct {
	GtkWidget *fixed;
	RPIChannelSet *rpichannel_set[MAX_CHANNELS_SET];
} RPIFixedSet;

RPIFixedSet * new_rpifixedset();
void show_rpifixedset(RPIFixedSet *rpifixedset_ptr);
void hide_rpifixedset(RPIFixedSet *rpifixedset_ptr);
void destroy_rpifixedset(RPIFixedSet *rpifixedset_ptr);

#endif

