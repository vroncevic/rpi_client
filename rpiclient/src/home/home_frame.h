/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * home_frame.h
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

#define MAX_CHANNELS_CONTROL_HOME_FRAME 8
#define MAX_CHANNELS_STATUS_HOME_FRAME 8

//////////////////////////////////////////////////////////////////////////////
/// @brief Home frame complex widget
typedef struct _HomeFrame HomeFrame;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget home frame
/// @return Home frame complex widget pointer
HomeFrame *new_home_frame(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show home frame complex widget
/// @param instance is pointer to complex widget home frame
void show_home_frame(HomeFrame *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide home frame complex widget
/// @param instance is pointer to complex widget home frame
void hide_home_frame(HomeFrame *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets frame from home frame complex widget
/// @param instance is pointer to complex widget home frame
/// @return Frame from complex widget home frame
GtkWidget* get_frame_home_frame(HomeFrame *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy home frame complex widget
/// @param instance is pointer to complex widget home frame
void destroy_home_frame(HomeFrame *instance);
