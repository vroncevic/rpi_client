/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * hboxsettings.h
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
#ifndef __HBOXSETTINGS_H
#define __HBOXSETTINGS_H

#include "resource.h"

#define TEXT_HBOXSETTINGS_BUTTON_OK	   "OK"
#define TEXT_HBOXSETTINGS_BUTTON_CANCEL   "Cancel"
#define WIDTH_HBOXSETTINGS_BUTTON_OK	  70
#define HEIGHT_HBOXSETTINGS_BUTTON_OK	 30

typedef struct {
	GtkWidget *hbox;
	GtkWidget *button_ok;
	GtkWidget *button_cancel;
} HBoxSettings;

HBoxSettings * new_hbox_settings();
void show_hbox_settings(HBoxSettings *hbox_settings_ptr);
void hide_hbox_settings(HBoxSettings *hbox_settings_ptr);
void destroy_hbox_settings(HBoxSettings *hbox_settings_ptr);

#endif

