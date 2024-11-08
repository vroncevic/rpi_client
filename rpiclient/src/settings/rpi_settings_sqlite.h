/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_settings_sqlite.h
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
/// @brief SQlite3 IO success status
#define SUCCESS_SETTINGS_SQLITE3 0

//////////////////////////////////////////////////////////////////////////////
/// @brief SQlite3 IO failed status
#define FAILED_SETTINGS_SQLITE3 1

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads server port settings configuration from file
/// @param file_server_port_config is FILE pointer for port settings configuration
/// @return Server port settings configuration parameter
gint rpi_settings_sqlite_open(const gchar* db_name);

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads server port settings configuration from file
/// @param file_server_port_config is FILE pointer for port settings configuration
/// @return Server port settings configuration parameter
gint rpi_settings_sqlite_close(void);
