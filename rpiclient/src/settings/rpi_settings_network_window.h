/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_network_window.h
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
/// @brief Settings network window complex widget
typedef struct _SettingsNetworkWindow SettingsNetworkWindow;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget settings network window
/// @return Settings network window complex widget pointer
SettingsNetworkWindow *new_settings_network_window(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show settings network window complex widget
/// @param instance is pointer to complex widget settings network window
void show_settings_network_window(SettingsNetworkWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide settings network window complex widget
/// @param instance is pointer to complex widget settings network window
void hide_settings_network_window(SettingsNetworkWindow *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy settings network window complex widget
/// @param instance is pointer to complex widget settings network window
void destroy_settings_network_window(SettingsNetworkWindow *instance);
