/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * entryport.h
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
#ifndef __ENTRYPORT_H
#define __ENTRYPORT_H

#include "resource.h"

#define TEXT_FRAME_ENTRY_PORT		"Server Port Number"
#define MAX_LENGTH_ENTRY_PORT		50
#define TEXT_EXAMPLE_ENTRY_PORT	  " exm: 9009"
#define NEW_TEXT_LENGTH_ENTRY_PORT   -1
#define START_POSITION_ENTRY_PORT	0

typedef struct {
	GtkWidget *frame;
	GtkWidget *entry;
	gint cur_pos_port;
} EntryPort;

EntryPort * new_entry_port();
void show_entry_port(EntryPort *entry_port_ptr);
void hide_entry_port(EntryPort *entry_port_ptr);
void destroy_entry_port(EntryPort *entry_port_ptr);

#endif

