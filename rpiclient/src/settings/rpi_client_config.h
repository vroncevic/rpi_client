/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_client_config.h
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

//////////////////////////////////////////////////////////////////////////////
/// @brief Enables verbose log messages
#define RPI_VERBOSE 1

//////////////////////////////////////////////////////////////////////////////
/// @brief Use SQLITE3 for keeping settings configuration
#define RPI_USE_SETTINGS_SQLITE3 0

//////////////////////////////////////////////////////////////////////////////
/// @brief Use PLAIN file for keeping settings configuration
#define RPI_USE_SETTINGS_PLAIN_CONFIG 0
