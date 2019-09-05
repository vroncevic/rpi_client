/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * vboxsettings.h
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
#ifndef __VBOXSETTINGS_H
#define __VBOXSETTINGS_H

#include "tablesettings.h"
#include "hboxsettings.h"

#define SPACING_VBOX_SETTINGS   20

typedef struct {
	GtkWidget *vbox;
	GtkWidget *halign;
	TableSettings *table_settings;
	HBoxSettings *hbox_settings;
} VBoxSettings;

VBoxSettings * new_vbox_settings();
void show_vbox_settings(VBoxSettings *vbox_settings_ptr);
void hide_vbox_settings(VBoxSettings *vbox_settings_ptr);
void destroy_vbox_settings(VBoxSettings *vbox_settings_ptr);

#endif

