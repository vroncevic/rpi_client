/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiframetop.h
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
#ifndef __RPIFRAMETOP_H
#define __RPIFRAMETOP_H

#include "rpiframeset.h"
#include "rpiframeget.h"

typedef struct {
	GtkWidget *frame;
	GtkWidget *vpaned;
	RPIFrameGet *frame_get;
	RPIFrameSet *frame_set;
} RPIFrameTop;

RPIFrameTop * new_rpiframetop();
void show_rpiframetop(RPIFrameTop *rpiframetop_ptr);
void hide_rpiframetop(RPIFrameTop *rpiframetop_ptr);
void destroy_rpiframetop(RPIFrameTop *rpiframetop_ptr);

#endif

