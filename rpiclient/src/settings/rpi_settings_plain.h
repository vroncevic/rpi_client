/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_plain.h
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

#include <stdio.h>
#include <gtk/gtk.h>

//////////////////////////////////////////////////////////////////////////////
/// @brief Plain file IO success status
#define SUCCESS_SETTINGS_PLAIN 0

//////////////////////////////////////////////////////////////////////////////
/// @brief Plain file IO failed status
#define FAILED_SETTINGS_PLAIN 1

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads prompt settings configuration from file
/// @return Prompt settings configuration parameter | NULL
gchar* rpi_read_prompt_settings_plain_file(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes prompt settings configuration parameter to file
/// @param prompt_config is prompt settings configuration parameter
/// @return Integer status 0 - success | 1 - failed
guint rpi_write_prompt_settings_plain_file(const gchar* prompt_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads server address settings configuration from file
/// @return Server address settings configuration parameter | NULL
gchar* rpi_read_address_settings_plain_file(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes server address settings configuration parameter to file
/// @param address_config is server address configuration parameter
/// @return Integer status 0 - success | 1 - failed
guint rpi_write_address_settings_plain_file(const gchar* address_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads server port settings configuration from file
/// @return Server port settings configuration parameter | NULL
gchar* rpi_read_port_settings_plain_file(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes server port settings configuration parameter to file
/// @param port_config is server port configuration parameter
/// @return Integer status 0 - success | 1 - failed
guint rpi_write_port_settings_plain_file(const gchar* port_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads exit settings configuration from file
/// @return Exit settings configuration parameter | NULL
gchar* rpi_read_exit_settings_plain_file(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes exit settings configuration parameter to file
/// @param exit_config is exit configuration parameter
/// @return Integer status 0 - success | 1 - failed
guint rpi_write_exit_settings_plain_file(const gchar* exit_config);
