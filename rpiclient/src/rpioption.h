/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpioption.h
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
#ifndef __RPIOPTION_H
#define __RPIOPTION_H

#include "rpioptionmenu.h"

#define MENU_ITEM_OPTION   "Option"

typedef struct {
	GtkWidget *option;
	RPIOptionMenu *option_menu;
} RPIOption;

RPIOption * new_rpioption();
void show_rpioption(RPIOption *rpioption_ptr);
void hide_rpioption(RPIOption *rpioption_ptr);
void destroy_rpioption(RPIOption *rpioption_ptr);

#endif

