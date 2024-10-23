/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * menu_bar.h
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

#define TEXT_MENU_FILE_MENU_BAR "File"
#define TEXT_MENU_FILE_SUBMENU_EXIT_MENU_BAR "Exit"
#define TEXT_MENU_OPTION_MENU_BAR "Option"
#define TEXT_MENU_OPTION_SUBMENU_CONNECT_MENU_BAR "Connect"
#define TEXT_MENU_OPTION_SUBMENU_DISCONNECT_MENU_BAR "Disconnect"
#define TEXT_MENU_SETTINGS_MENU_BAR "Settings"
#define TEXT_MENU_SETTINGS_SUBMENU_NETWORK_MENU_BAR "Network"
#define TEXT_MENU_HELP_MENU_BAR "Help"
#define TEXT_MENU_HELP_SUBMENU_HELP_MENU_BAR "Help"
#define TEXT_MENU_HELP_SUBMENU_ABOUT_MENU_BAR "About"
#define WARNING_LOG_FAILED_MALLOC_MENU_BAR "Failed to allocate memory for menu bar\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Menu bar complex widget
///   menu_bar - Gtk menu bar widget
///   menu_file - Gtk menu item widget for file
///   menu_file_submenu_quit - Gtk menu item widget for submenu exit
///   menu_option - Gtk menu item widget for option
///   menu_option_submenu_connect - Gtk menu item widget for submenu connect
///   menu_option_submenu_disconnect - Gtk menu item widget for submenu disconnect
///   menu_settings - Gtk menu item widget for settings
///   menu_settings_submenu_network - Gtk menu item widget for submenu network
///   menu_help - Gtk menu item widget for help 
///   menu_help_submenu_help - Gtk menu item widget for submenu help
///   menu_help_submenu_about - Gtk menu item widget for submenu about
typedef struct
{
	GtkWidget *menu_bar;
	GtkWidget *menu_file;
	GtkWidget *menu_file_submenu_exit;
	GtkWidget *menu_option;
	GtkWidget *menu_option_submenu_connect;
	GtkWidget *menu_option_submenu_disconnect;
	GtkWidget *menu_settings;
	GtkWidget *menu_settings_submenu_network;
	GtkWidget *menu_help;
	GtkWidget *menu_help_submenu_help;
	GtkWidget *menu_help_submenu_about;
} MenuBar;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget menu bar
/// @return Menu bar complex widget pointer
MenuBar *new_menu_bar(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show menu bar complex widget
/// @param instance is pointer to complex widget menu bar
void show_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide menu bar complex widget
/// @param instance is pointer to complex widget menu bar
void hide_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy menu bar complex widget
/// @param instance is pointer to complex widget menu bar
void destroy_menu_bar(MenuBar *instance);
