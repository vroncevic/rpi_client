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
#define SUCCESS_SETTINGS_SQLITE 0

//////////////////////////////////////////////////////////////////////////////
/// @brief SQlite3 IO failed status
#define FAILED_SETTINGS_SQLITE 1

//////////////////////////////////////////////////////////////////////////////
/// @brief Read no_prompt settings configuration from database
/// @return Prompt settings configuration | NULL
gchar* rpi_read_no_prompt_settings_sqlite(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes no_prompt settings configuration to database
/// @param no_prompt is settings configuration for prompt option
/// @return Integer status 0 - success | 1 - failed
gint rpi_write_no_prompt_settings_sqlite(const gchar* no_prompt);

//////////////////////////////////////////////////////////////////////////////
/// @brief Read ip_address settings configuration from database
/// @return Server ip address settings configuration | NULL
gchar* rpi_read_ip_address_settings_sqlite(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes server port settings configuration from file
/// @param ip_address is settings configuration for server ip address
/// @return Integer status 0 - success | 1 - failed
gint rpi_write_ip_address_settings_sqlite(const gchar* ip_address);

//////////////////////////////////////////////////////////////////////////////
/// @brief Read port_number settings configuration from database
/// @return Server port number settings configuration | NULL
gchar* rpi_read_port_number_settings_sqlite(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes server port settings configuration from file
/// @param port_number is settings configuration for server port number
/// @return Integer status 0 - success | 1 - failed
gint rpi_write_port_number_settings_sqlite(const gchar* port_number);

//////////////////////////////////////////////////////////////////////////////
/// @brief Read no_exit settings configuration from database
/// @return Exit settings configuration | NULL
gchar* rpi_read_no_exit_settings_sqlite(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes no_exit settings configuration to database
/// @param no_exit is settings configuration for exit option
/// @return Integer status 0 - success | 1 - failed
gint rpi_write_no_exit_settings_sqlite(const gchar* no_exit);
