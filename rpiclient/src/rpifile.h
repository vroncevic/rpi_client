/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpifile.h
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
#ifndef __RPIFILE_H
#define __RPIFILE_H

#include "rpifilemenu.h"

#define MENU_ITEM_FILE   "File"

typedef struct {
	GtkWidget *file;
	RPIFileMenu *file_menu;
} RPIFile;

RPIFile * new_rpifile();
void show_rpifile(RPIFile *rpifile_ptr);
void hide_rpifile(RPIFile *rpifile_ptr);
void destroy_rpifile(RPIFile *rpifile_ptr);

#endif

