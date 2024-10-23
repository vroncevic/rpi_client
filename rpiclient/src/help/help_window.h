/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * help_window.h
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

#include "image_slider.h"

#define TITLE_HELP_WINDOW "Help"
#define BORDER_WIDTH_HELP_WINDOW (10)
#define WIDTH_HELP_WINDOW (300)
#define HEIGHT_HELP_WINDOW (200)
#define ICON_HELP_WINDOW "icon.png"
#define WARNING_LOG_FAILED_MALLOC_HELP_WINDOW "Failed to allocate memory for help window\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Help window complex widget
///   window - Gtk window widget
///   image_slider - Complex image slider widget
typedef struct
{
    GtkWidget *window;
    ImageSlider *image_slider;
} HelpWindow;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget help window
/// @return Help window complex widget pointer
HelpWindow *new_help_window(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show help window complex widget
/// @param instance is pointer to complex widget help window
void show_help_window(HelpWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide help window complex widget
/// @param instance is pointer to complex widget help window
void hide_help_window(HelpWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy help window complex widget
/// @param instance is pointer to complex widget help window
void destroy_help_window(HelpWindow *instance);
