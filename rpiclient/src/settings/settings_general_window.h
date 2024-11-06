/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_general_window.h
 * Copyright (C) 2016 - 2024 Vladimir Roncevic <elektron.ronca@gmail.com>
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
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <gtk/gtk.h>
#include "../resource/resource.h"

#define TITLE_SETTINGS_GENERAL_WINDOW "Settings General"
#define ICON_SETTINGS_GENERAL_WINDOW "icon.png"
#define WIDTH_SETTINGS_GENERAL_WINDOW (350)
#define HEIGHT_SETTINGS_GENERAL_WINDOW (350)
#define CONTAINER_BORDER_WIDTH_SETTINGS_GENERAL_WINDOW (10)
#define SPACING_VBOX_SETTINGS_GENERAL_WINDOW (20)
#define TABLE_ROW_SPACINGS_TABLE_SETTINGS_GENERAL_WINDOW (10)
#define TABLE_COL_SPACINGS_TABLE_SETTINGS_GENERAL_WINDOW (10)
#define TEXT_BUTTON_OK_HBOX_SETTINGS_GENERAL_WINDOW "OK"
#define TEXT_BUTTON_CANCEL_HBOX_SETTINGS_GENERAL_WINDOW "Cancel"
#define WIDTH_BUTTON_HBOX_SETTINGS_GENERAL_WINDOW (70)
#define HEIGHT_BUTTON_HBOX_SETTINGS_GENERAL_WINDOW (30)
#define SPACING_HBOX_SETTINGS_GENERAL_WINDOW (3)
#define WARNING_LOG_FAILED_MALLOC_SETTINGS_GENERAL_WINDOW "Failed to allocate memory for settings general window\n"
#define WARNING_LOG_FAILED_PIXBUF_SETTINGS_GENERAL_WINDOW "Failed to create pixbuf from settings general icon.\n"
#define WARNING_LOG_FAILED_RESOURCE_SETTINGS_GENERAL_WINDOW "Failed to get resource path for settings general icon\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings general window complex widget
///   window - Gtk window widget
///   vbox - Gtk widget for vertical box
///   table - Gtk widget for table
///   hbox - Gtk widget for horizontal alignment
///   button_ok - Gtk widget for ok action
///   button_cancel - Gtk widget for cancel action
typedef struct
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *table;
    GtkWidget *hbox;
    GtkWidget *button_ok;
    GtkWidget *button_cancel;
} SettingsGeneralWindow;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget settings general window
/// @return Settings general window complex widget pointer
SettingsGeneralWindow *new_settings_general_window(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show settings general window complex widget
/// @param instance is pointer to complex widget settings general window
void show_settings_general_window(SettingsGeneralWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide settings general window complex widget
/// @param instance is pointer to complex widget settings general window
void hide_settings_general_window(SettingsGeneralWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy settings general window complex widget
/// @param instance is pointer to complex widget settings general window
void destroy_settings_general_window(SettingsGeneralWindow *instance);
