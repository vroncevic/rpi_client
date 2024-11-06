/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * settings_network_window.h
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

#include "../resource/resource.h"

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings network window complex widget
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
} SettingsNetworkWindow;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget settings network window
/// @return Settings network window complex widget pointer
SettingsNetworkWindow *new_settings_network_window(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show settings network window complex widget
/// @param instance is pointer to complex widget settings network window
void show_settings_network_window(SettingsNetworkWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide settings network window complex widget
/// @param instance is pointer to complex widget settings network window
void hide_settings_network_window(SettingsNetworkWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy settings network window complex widget
/// @param instance is pointer to complex widget settings network window
void destroy_settings_network_window(SettingsNetworkWindow *instance);
