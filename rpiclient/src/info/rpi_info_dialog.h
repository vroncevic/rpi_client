/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_info_dialog.h
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
/// @brief Info dialog complex widget
typedef struct _InfoDialog InfoDialog;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget info dialog
/// @param parent is parent widget
/// @param msg is message for info dialog
/// @return Info dialog complex widget pointer
InfoDialog *new_info_dialog(GtkWidget *parent, const gchar *msg);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show info dialog complex widget
/// @param instance is pointer to complex widget info dialog
void show_info_dialog(InfoDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide info dialog complex widget
/// @param instance is pointer to complex widget info dialog
void hide_info_dialog(InfoDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy info dialog complex widget
/// @param instance is pointer to complex widget info dialog
void destroy_info_dialog(InfoDialog *instance);
