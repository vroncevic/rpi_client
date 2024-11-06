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

#include "home_frame.h"
#include "menu_bar.h"

//////////////////////////////////////////////////////////////////////////////
/// @brief Home complex widget
typedef struct _Home Home;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget home
/// @return Home view complex widget pointer
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
/// @brief Gets window from home complex widget
/// @param instance is pointer to complex widget home
/// @return Window from complex widget home
GtkWidget* get_window_home(Home *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets menu bar from home complex widget
/// @param instance is pointer to complex widget home
/// @return Menu bar from complex widget home
MenuBar* get_bar_home(Home *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy home complex widget
/// @param instance is pointer to complex widget home
void destroy_home(Home *instance);
