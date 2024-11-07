/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_warning_dialog.h
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

#include "../resource/rpi_resource.h"

//////////////////////////////////////////////////////////////////////////////
/// @brief Warning dialog complex widget
typedef struct _WarningDialog WarningDialog;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget warning dialog
/// @param parent is parent widget for dialog
/// @param msg is message for warning dialog
/// @return About dialog complex widget pointer
WarningDialog *new_warning_dialog(GtkWidget *parent, const gchar *msg);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show warning dialog complex widget
/// @param instance is pointer to complex widget warning dialog
void show_warning_dialog(WarningDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide warning dialog complex widget
/// @param instance is pointer to complex widget warning dialog
void hide_warning_dialog(WarningDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy warning dialog complex widget
/// @param instance is pointer to complex widget warning dialog
void destroy_warning_dialog(WarningDialog *instance);
