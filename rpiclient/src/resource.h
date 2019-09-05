/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * resource.h
 * Copyright (C) 2016 Vladimir Roncevic <elektron.ronca@gmail.com>
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
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __RESOURCE_H
#define __RESOURCE_H

#include <glib.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <cairo.h>
#include "serverparameters.h"
#include "gthreadparameters.h"

#define RESOURCE_PATH   "/images/"
#define PORT_NUMBER_SERVER "8000"
#define SERVER_ADDRESS "127.0.0.1"

extern ServerParameters *server_parameters;
extern GThreadParameters *gthread_parameters;

GdkPixbuf* cpixbuf(const gchar *path);

#endif

