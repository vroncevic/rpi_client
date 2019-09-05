/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpimenubar.h
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
#ifndef __RPIMENUBAR_H
#define __RPIMENUBAR_H

#include "rpifile.h"
#include "rpioption.h"
#include "rpihelp.h"
#include "rpiabout.h"

typedef struct {
	GtkWidget *menubar;
	RPIFile *file_item;
	RPIOption *option_item;
	RPIHelp *help_item;
	RPIAbout *about_item;
} RPIMenuBar;

RPIMenuBar * new_rpimenubar();
void show_rpimenubar(RPIMenuBar *rpimenubar_ptr);
void hide_rpimenubar(RPIMenuBar *rpimenubar_ptr);
void destroy_rpimenubar(RPIMenuBar *rpimenubar_ptr);

#endif

