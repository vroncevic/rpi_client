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

//////////////////////////////////////////////////////////////////////////////
/// @brief Menu bar complex widget
typedef struct _MenuBar MenuBar;

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
/// @brief Gets bar from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return Menu bar widget
GtkWidget* get_bar_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets exit from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return Exit menu bar item widget
GtkWidget* get_exit_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets connect from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return Connect menu bar item widget
GtkWidget* get_connect_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets disconnect from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return Disconnect menu bar item widget
GtkWidget* get_disconnect_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets general settings from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return General settings menu bar item widget
GtkWidget* get_general_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets network settings from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return Network settings menu bar item widget
GtkWidget* get_network_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets help from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return Help menu bar item widget
GtkWidget* get_help_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets about from menu bar complex widget
/// @param instance is pointer to complex widget menu bar
/// @return About menu bar item widget
GtkWidget* get_about_menu_bar(MenuBar *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy menu bar complex widget
/// @param instance is pointer to complex widget menu bar
void destroy_menu_bar(MenuBar *instance);
