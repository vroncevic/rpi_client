/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * helpwindow.h
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
#ifndef __HELPWINDOW_H
#define __HELPWINDOW_H

#include "imageslider.h"

#define TITLE_HELP_WINDOW					"Help"
#define CONTAINER_BORDER_WIDTH_HELP_WINDOW   10
#define WIDTH_HELP_WINDOW					300
#define HEIGHT_HELP_WINDOW				   200

typedef struct {
	GtkWidget *window;
	ImageSlider *image_slider;
} HelpWindow;

HelpWindow * new_help_window();
void show_help_window(HelpWindow *help_window_ptr);
void hide_help_window(HelpWindow *help_window_ptr);
void destroy_help_window(HelpWindow *help_window_ptr);

#endif

