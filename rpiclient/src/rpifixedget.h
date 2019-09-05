/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpifixedget.h
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
#ifndef __RPIFIXEDGET_H
#define __RPIFIXEDGET_H

#include "rpichannelget.h"

#define MAX_CHANNELS_GET						8
#define START_X_POSITION_VERTICAL_BAR_GET	   0
#define Y_POSITION_VERTICAL_BAR_GET			 45
#define START_X_POSITION_ACTIVATE_CHANNEL_GET   0
#define Y_POSITION_ACTIVATE_CHANNEL_GET		 1
#define START_X_POSITION_LABEL_GET			  0
#define Y_POSITION_LABEL_GET					25
#define SHIFT_X_POSITION_GET					120

typedef struct {
	GtkWidget *fixed;
	RPIChannelGet *rpichannel_get[MAX_CHANNELS_GET];
} RPIFixedGet;

RPIFixedGet * new_rpifixedget();
void show_rpifixedget(RPIFixedGet *rpifixedget_ptr);
void hide_rpifixedget(RPIFixedGet *rpifixedget_ptr);
void destroy_rpifixedget(RPIFixedGet *rpifixedget_ptr);

#endif

