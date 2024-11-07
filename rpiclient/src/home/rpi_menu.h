/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_menu.h
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
/// @brief Menu bar RPI complex widget
typedef struct _RPIMenu RPIMenu;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget RPI menu bar
/// @return RPI menu bar complex widget pointer
RPIMenu *new_rpi_menu(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
void show_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
void hide_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets menu bar from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return Menu bar widget from RPI menu bar complex widget
GtkWidget* get_menu_bar_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets exit item from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return Exit item from RPI menu bar complex widget
GtkWidget* get_exit_item_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets connect item from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return Connect item from RPI menu bar complex widget
GtkWidget* get_connect_item_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets disconnect item from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return Disconnect item from RPI menu bar complex widget
GtkWidget* get_disconnect_item_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets general settings item from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return General settings item from RPI menu bar complex widget
GtkWidget* get_general_item_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets network settings item from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return Network settings item from RPI menu bar complex widget
GtkWidget* get_network_item_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets help item from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return Help item from RPI menu bar complex widget
GtkWidget* get_help_item_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets about item from RPI menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
/// @return About item from RPI menu bar complex widget
GtkWidget* get_about_item_from_rpi_menu(RPIMenu *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy menu bar complex widget
/// @param instance is pointer to complex widget RPI menu bar
void destroy_rpi_menu(RPIMenu *instance);
