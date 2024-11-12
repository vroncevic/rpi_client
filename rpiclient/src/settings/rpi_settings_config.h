/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_config.h
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

#include <glib.h>

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings configuration IO success status
#define SUCCESS_IO_SETTINGS_CONFIGURATION 0

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings configuration IO failed status
#define FAILED_IO_SETTINGS_CONFIGURATION 1

//////////////////////////////////////////////////////////////////////////////
/// @brief Settings configuration structure
typedef struct _SettingsConfig SettingsConfig;

//////////////////////////////////////////////////////////////////////////////
/// @brief Read configuration from files
/// @return Settings configuration structure pointer
SettingsConfig* settings_read(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Write settings configuration to file
/// @param instance is pointer to settings configuration to be written
/// @return Integer status 0 - success | 1 - failed
guint settings_write(const SettingsConfig* instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets prompt from settings file
/// @param instance is pointer to settings configuration to be written
/// @return Boolean statis is prompt enabled
gboolean is_prompt_enabled_settings(const SettingsConfig* instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets server ip address from settings file
/// @param instance is pointer to settings configuration to be written
/// @return IP server address in string format
gchar* get_server_ip_address_from_settings(const SettingsConfig* instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets server port number from settings file
/// @param instance is pointer to settings configuration to be written
/// @return Port number of server in string format
gchar* get_server_port_number_from_settings(const SettingsConfig* instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets exit from settings file
/// @param instance is pointer to settings configuration to be written
/// @return Boolean statis is exit enabled
gboolean is_exit_enabled_settings(const SettingsConfig* instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Free settings configuration memory
/// @param instance is pointer to settings configuration to be free
void settings_free(SettingsConfig* instance);
