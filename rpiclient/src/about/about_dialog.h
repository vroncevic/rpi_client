/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * about_dialog.h
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

#define TEXT_NAME_ABOUT_DIALOG "Home"
#define TEXT_VERSION_ABOUT_DIALOG "1.0.0"
#define TEXT_COPYRIGHT_ABOUT_DIALOG "2024 (c) elektron.ronca@gmail.com"
#define TEXT_COMMENTS_ABOUT_DIALOG "Free Software you can redistribute it and/or modify it."
#define TEXT_WEBSITE_ABOUT_DIALOG "https://github.com/vroncevic/rpiclient-gtk"
#define LOGO_FILE_NAME_ABOUT_DIALOG "logo.png"
#define WARNING_LOG_FAILED_MALLOC_ABOUT_DIALOG "Failed to allocate memory for About dialog\n"
#define WARNING_LOG_FAILED_PIXBUF_ABOUT_DIALOG "Failed to create pixbuf from about logo.\n"
#define WARNING_LOG_FAILED_RESOURCE_ABOUT_DIALOG "Failed to get resource path for about logo\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief About dialog complex widget
///   dialog - Gtk about dialog widget
typedef struct
{
    GtkWidget *dialog;
} AboutDialog;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget about dialog
/// @return About dialog complex widget pointer
AboutDialog *new_about_dialog(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show about dialog complex widget
/// @param instance is pointer to complex widget about dialog
void show_about_dialog(AboutDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide about dialog complex widget
/// @param instance is pointer to complex widget about dialog
void hide_about_dialog(AboutDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy about dialog complex widget
/// @param instance is pointer to complex widget about dialog
void destroy_about_dialog(AboutDialog *instance);
