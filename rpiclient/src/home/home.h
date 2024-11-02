/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * home.h
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

#include "menu_bar.h"
#include "home_frame.h"
#include "../settings/settings_config.h"
#include "../encrypt/rpi_format.h"

#define TITLE_WINDOW_HOME "RPIClient v1.0"
#define WIDTH_WINDOW_HOME (900)
#define HEIGHT_WINDOW_HOME (400)
#define CONTAINER_BORDER_WIDTH_WINDOW_HOME (2)
#define WARNING_LOG_FAILED_MALLOC_HOME "Failed to allocate memory for home\n"
#define WARNING_LOG_FAILED_MALLOC_WINDOW_HOME "Failed to allocate memory for home window\n"
#define WARNING_LOG_FAILED_PIXBUF_HOME "Failed to create pixbuf from home icon.\n"
#define WARNING_LOG_FAILED_RESOURCE_HOME "Failed to get resource path for home icon\n"
#define WARNING_LOG_FAILED_MALLOC_VBOX_HOME "Failed to allocate memory for vertial box home\n"
#define WARNING_LOG_FAILED_MALLOC_MENU_BAR_HOME "Failed to allocate memory for menu bar home\n"
#define WARNING_LOG_FAILED_MALLOC_HOME_FRAME_HOME "Failed to allocate memory for frame home\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief About dialog complex widget
///   window - Gtk window widget for home
///   vbox - Gtk vertial box widget for home
///   menu_bar - Complex widget for menu bar
///   frame_home - Complex widget for home frame
typedef struct
{
    GtkWidget *window;
    GtkWidget *vbox;
    MenuBar *menu_bar;
    HomeFrame *frame_home;
} Home;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget home
/// @return About dialog complex widget pointer
Home *new_home(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show home complex widget
/// @param instance is pointer to complex widget home
void show_home(Home *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide home complex widget
/// @param instance is pointer to complex widget home
void hide_home(Home *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy home complex widget
/// @param instance is pointer to complex widget home
void destroy_home(Home *instance);
