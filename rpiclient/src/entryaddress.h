/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * entryaddress.h
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
#ifndef __ENTRYADDRESS_H
#define __ENTRYADDRESS_H

#include "resource.h"

#define TEXT_FRAME_ENTRY_ADDRESS		"Server IP Address"
#define MAX_LENGTH_ENTRY_ADDRESS		50
#define TEXT_EXAMPLE_ENTRY_ADDRESS	  " exm: 192.168.1.115"
#define NEW_TEXT_LENGTH_ENTRY_ADDRESS   -1
#define START_POSITION_ENTRY_ADDRESS	0

typedef struct {
	GtkWidget *frame;
	GtkWidget *entry;
	gint cur_pos_address;
} EntryAddress;

EntryAddress * new_entry_address();
void show_entry_address(EntryAddress *entry_address_ptr);
void hide_entry_address(EntryAddress *entry_address_ptr);
void destroy_entry_address(EntryAddress *entry_address_ptr);

#endif

