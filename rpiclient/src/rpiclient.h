/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiclient.h
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
#ifndef __RPICLIENT_H
#define __RPICLIENT_H

#include "rpivbox.h"
#include "config.h"
#include "rpiformat.h"

#define TITLE_RPICLIENT_WINDOW					"RPIClient v1.0"
#define WIDTH_RPICLIENT_WINDOW					250
#define HEIGHT_RPICLIENT_WINDOW				   450
#define CONTAINER_BORDER_WIDTH_RPICLIENT_WINDOW   2

typedef struct {
	GtkWidget *window;
	RPIVBox *rpivbox_top;
} RPIClient;

RPIClient * new_rpiclient();
void show_rpiclient(RPIClient *rpiclient_ptr);
void hide_rpiclient(RPIClient *rpiclient_ptr);
void destroy_rpiclient(RPIClient *rpiclient_ptr);

#endif

