/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_window.h
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

#define TITLE_SETTINGS_WINDOW "Settings"
#define ICON_SETTINGS_WINDOW "icon.png"
#define WIDTH_SETTINGS_WINDOW (350)
#define HEIGHT_SETTINGS_WINDOW (350)
#define CONTAINER_BORDER_WIDTH_SETTINGS_WINDOW (10)
#define SPACING_VBOX_SETTINGS_WINDOW (20)
#define TABLE_ROWS_TABLESETTINGS (2)
#define TABLE_COLS_TABLESETTINGS (1)
#define TABLE_ROW_SPACINGS_TABLESETTINGS (10)
#define TABLE_COL_SPACINGS_TABLESETTINGS (10)
#define TEXT_FRAME_CONTORL_EXIT "Exit Operation"
#define TEXT_CHECK_BUTTON_CONTROL_EXIT "Display Exit Dialog on Quit?"
#define TEXT_FRAME_ENTRY_ADDRESS "Server IP Address"
#define MAX_LENGTH_ENTRY_ADDRESS (50)
#define TEXT_EXAMPLE_ENTRY_ADDRESS " exm: 192.168.1.115"
#define NEW_TEXT_LENGTH_ENTRY_ADDRESS (-1)
#define START_POSITION_ENTRY_ADDRESS (0)
#define TEXT_FRAME_ENTRY_PORT "Server Port Number"
#define MAX_LENGTH_ENTRY_PORT (50)
#define TEXT_EXAMPLE_ENTRY_PORT " exm: 9009"
#define NEW_TEXT_LENGTH_ENTRY_PORT (-1)
#define START_POSITION_ENTRY_PORT (0)
#define TEXT_BUTTON_OK_HBOX_SETTINGS "OK"
#define TEXT_BUTTON_CANCEL_HBOX_SETTINGS "Cancel"
#define WIDTH_BUTTON_HBOX_SETTINGS (70)
#define HEIGHT_BUTTON_HBOX_SETTINGS (30)
#define SPACING_HBOX_SETTINGS (3)
#define WARNING_LOG_FAILED_MALLOC_SETTINGS_WINDOW "Failed to allocate memory for settings window\n"
#define WARNING_LOG_FAILED_PIXBUF_SETTINGS_WINDOW "Failed to create pixbuf from settings icon.\n"
#define WARNING_LOG_FAILED_RESOURCE_SETTINGS_WINDOW "Failed to get resource path for settings icon\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings window complex widget
///   window - Gtk window widget
///   vbox - Gtk widget for vertical box
///   table - Gtk widget for table
///   frame_control_exit - Gtk widget for frame 
///   check_button_control_exit - Gtk widget for check box
///   frame_entry_address - Gtk widget for frame
///   entry_address - Gtk widget for entry
///   cur_pos_address - Cursor position
///   frame_entry_port - Gtk widget for frame
///   entry_port - Gtk widget for entry
///   cur_pos_port - Cursor position for entry
///   hbox - Gtk widget for horizontal alignment
///   button_ok - Gtk widget for ok action
///   button_cancel - Gtk widget for cancel action
typedef struct
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *table;
    GtkWidget *frame_control_exit;
    GtkWidget *check_button;
    GtkWidget *frame_entry_address;
    GtkWidget *entry_address;
    gint cur_pos_address;
    GtkWidget *frame_entry_port;
    GtkWidget *entry_port;
    gint cur_pos_port;
    GtkWidget *hbox;
    GtkWidget *button_ok;
    GtkWidget *button_cancel;
} SettingsWindow;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget settings window
/// @return Settings window complex widget pointer
SettingsWindow *new_settings_window(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show settings window complex widget
/// @param instance is pointer to complex widget settings window
void show_settings_window(SettingsWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide settings window complex widget
/// @param instance is pointer to complex widget settings window
void hide_settings_window(SettingsWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy settings window complex widget
/// @param instance is pointer to complex widget settings window
void destroy_settings_window(SettingsWindow *instance);
