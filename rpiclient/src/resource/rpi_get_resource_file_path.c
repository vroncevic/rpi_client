/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpi_get_resource_file_path.c
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
#include "rpi_resource.h"

gchar *rpi_get_resource_file_path(const gchar *file_name)
{
    if (!file_name || !resource_dir_path)
    {
        return NULL;
    }

    gchar *file_path = g_strjoin(NULL, resource_dir_path, file_name, NULL);

    if (!g_file_test(file_path, G_FILE_TEST_EXISTS))
    {
        g_free((gpointer)file_path);
        return NULL;
    }

    return file_path;
}
