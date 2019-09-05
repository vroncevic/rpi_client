/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpivbox.h
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
#ifndef __RPIVBOX_H
#define __RPIVBOX_H

#include "rpimenubar.h"
#include "rpiframetop.h"

typedef struct {
	GtkWidget *vbox;
	RPIMenuBar *menu_bar;
	RPIFrameTop *frame_top;
} RPIVBox;

RPIVBox * new_rpivbox();
void show_rpivbox(RPIVBox *rpivbox_ptr);
void hide_rpivbox(RPIVBox *rpivbox_ptr);
void destroy_rpivbox(RPIVBox *rpivbox_ptr);

#endif

