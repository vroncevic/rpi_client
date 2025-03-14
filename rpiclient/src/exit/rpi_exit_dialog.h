/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_exit_dialog.h
 * Copyright (C) 2016 - 2025 Vladimir Roncevic <elektron.ronca@gmail.com>
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

#define CLOSE_ON_EXIT_DIALOG 0
#define NOT_CLOSE_ON_EXIT_DIALOG 1

//////////////////////////////////////////////////////////////////////////////
/// @brief Exit dialog complex widget
typedef struct _ExitDialog ExitDialog;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget exit dialog
/// @param widget is parent widget (another window | dialog)
/// @return Exit dialog complex widget pointer | NULL
ExitDialog *new_exit_dialog(GtkWidget *widget);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show exit dialog complex widget
/// @param instance is pointer to complex widget exit dialog
/// @return Integer status 0 - close | 1 - not close
gint show_exit_dialog(ExitDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide exit dialog complex widget
/// @param instance is pointer to complex widget exit dialog
void hide_exit_dialog(ExitDialog *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy exit dialog complex widget
/// @param instance is pointer to complex widget exit dialog
void destroy_exit_dialog(ExitDialog *instance);
