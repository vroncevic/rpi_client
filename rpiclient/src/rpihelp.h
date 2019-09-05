/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpihelp.h
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
#ifndef __RPIHELP_H
#define __RPIHELP_H

#include "resource.h"

#define MENU_ITEM_HELP   "Help"

typedef struct {
	GtkWidget *help_subitem;
} RPIHelp;

RPIHelp * new_rpihelp();
void show_rpihelp(RPIHelp *rpihelp_ptr);
void hide_rpihelp(RPIHelp *rpihelp_ptr);
void destroy_rpihelp(RPIHelp *rpihelp_ptr);

#endif

