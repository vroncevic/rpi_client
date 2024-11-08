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
#include "../resource/rpi_resource.h"

//////////////////////////////////////////////////////////////////////////////
/// @brief Plain file IO success status
#define SUCCESS_SETTINGS_PLAIN 0

//////////////////////////////////////////////////////////////////////////////
/// @brief Plain file IO failed status
#define FAILED_SETTINGS_PLAIN 1

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets prompt settings configuration file
/// @param mode is file operation mode
/// @return FILE pointer for prompt settings configuration
FILE* rpi_get_prompt_settings_plain_file(const gchar* mode);

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads prompt settings configuration from file
/// @param prompt_config_file is FILE pointer for prompt settings configuration
/// @return Prompt settings configuration parameter
gchar* rpi_read_prompt_settings_plain_file(FILE* prompt_config_file);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes prompt settings configuration parameter to file
/// @param prompt_config_file is FILE pointer for prompt settings configuration
/// @param prompt_config is prompt settings configuration parameter
/// @return Integer status 0 - success | 1 - failed
guint rpi_write_prompt_settings_plain_file(FILE* prompt_config_file, const gchar* prompt_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Closes prompt settings configuration file
/// @param prompt_config_file is FILE pointer for prompt settings configuration
void rpi_close_prompt_settings_plain_file(FILE* prompt_config_file);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets server address settings configuration file
/// @param mode is file operation mode
/// @return FILE pointer for server address settings configuration
FILE* rpi_get_address_settings_plain_file(const gchar* mode);

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads server address settings configuration from file
/// @param file_server_address_config is FILE pointer for address settings configuration
/// @return Server address settings configuration parameter
gchar* rpi_read_address_settings_plain_file(FILE* file_server_address_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes server address settings configuration parameter to file
/// @param file_server_address_config is FILE pointer for address configuration
/// @param address_config is server address configuration parameter
/// @return Integer status 0 - success | 1 - failed
guint rpi_write_address_settings_plain_file(FILE* file_server_address_config, const gchar* address_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Closes address settings configuration file
/// @param file_server_address_config is FILE pointer for address settings configuration
void rpi_close_address_settings_plain_file(FILE* file_server_address_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets server port settings configuration file
/// @param mode is file operation mode
/// @return FILE pointer for server port settings configuration
FILE* rpi_get_port_settings_plain_file(const gchar* mode);

//////////////////////////////////////////////////////////////////////////////
/// @brief Reads server port settings configuration from file
/// @param file_server_port_config is FILE pointer for port settings configuration
/// @return Server port settings configuration parameter
gchar* rpi_read_port_settings_plain_file(FILE* file_server_port_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Writes server port settings configuration parameter to file
/// @param file_server_port_config is FILE pointer for port configuration
/// @param port_config is server port configuration parameter
/// @return Integer status 0 - success | 1 - failed
guint rpi_write_port_settings_plain_file(FILE* file_server_port_config, const gchar* port_config);

//////////////////////////////////////////////////////////////////////////////
/// @brief Closes port settings configuration file
/// @param file_server_port_config is FILE pointer for port settings configuration
void rpi_close_port_settings_plain_file(FILE* file_server_port_config);
