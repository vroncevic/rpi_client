/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpioptionmenu.h
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
#ifndef __RPIOPTIONMENU_H
#define __RPIOPTIONMENU_H

#include "rpiconnect.h"
#include "rpidisconnect.h"
#include "rpisend.h"
#include "rpisettings.h"

typedef struct {
	GtkWidget *option_menu;
	RPIConnect *connect;
	RPIDisconnect *disconnect;
	RPISend *send;
	RPISettings *settings;
} RPIOptionMenu;

RPIOptionMenu * new_rpioptionmenu();
void show_rpioptionmenu(RPIOptionMenu *rpioptionmenu_ptr);
void hide_rpioptionmenu(RPIOptionMenu *rpioptionmenu_ptr);
void destroy_rpioptionmenu(RPIOptionMenu *rpioptionmenu_ptr);

#endif

