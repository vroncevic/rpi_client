/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_resource.h
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
#include <gtk/gtk.h>

extern gchar *resource_dir_path;
extern gchar *config_dir_path;

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets pixel buffer from file path
/// @param file_path is pixel file path
/// @return Pixel buffer structure | NULL
GdkPixbuf *rpi_cpixbuf(const gchar *file_path);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets resource directory path
/// @return Directory path for resource | NULL
gchar *rpi_get_resource_dir(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets resource file path
/// @param file_name is resource file name
/// @return File path for resource | NULL
gchar *rpi_get_resource_file_path(const gchar *file_name);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets configuration directory path
/// @return Directory path for configuration | NULL
gchar *rpi_get_config_dir(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets configuration file path
/// @param file_name is configuration file name
/// @param default_content is default parameter content
/// @return File path for configuration | NULL
gchar *rpi_get_config_file_path(const gchar *file_name, const gchar *default_content);
