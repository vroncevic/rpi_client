/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settingswindow.h
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
#ifndef __SETTINGSWINDOW_H
#define __SETTINGSWINDOW_H

#include "vboxsettings.h"

#define TITLE_SETTINGS_WINDOW					"Settings"
#define WIDTH_SETTINGS_WINDOW					350
#define HEIGHT_SETTINGS_WINDOW				   350
#define CONTAINER_BORDER_WIDTH_SETTINGS_WINDOW   10

typedef struct {
	GtkWidget *window;
	VBoxSettings *vbox_settings;
} SettingsWindow;

SettingsWindow * new_settings_window();
void show_settings_window(SettingsWindow *settings_window_ptr);
void hide_settings_window(SettingsWindow *settings_window_ptr);
void destroy_settings_window(SettingsWindow *settings_window_ptr);

#endif

