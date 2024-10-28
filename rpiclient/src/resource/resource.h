/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * resource.h
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

#include <glib.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <cairo.h>
#include "../settings/server_parameters.h"
#include "../settings/gthread_parameters.h"

#define RPIC_RES_PATH "/images/"
#define RPIC_RES_CONFIG "/config/"
#define RPIC_PORT_NUMBER_SERVER "8000"
#define RPIC_SERVER_ADDRESS "127.0.0.1"

extern ServerParameters *server_parameters;
extern GThreadParameters *gthread_parameters;
extern gchar *resource_dir_path;
extern gchar *config_dir_path;

GdkPixbuf *cpixbuf(const gchar *file_path);
gchar *get_resource_dir(void);
gchar *get_resource_file(const gchar *file_name);
gchar *get_config_dir(void);
gchar *get_config_file(const gchar *file_name);