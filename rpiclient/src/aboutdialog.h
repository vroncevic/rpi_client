/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * aboutdialog.h
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
#ifndef __ABOUTDIALOG_H
#define __ABOUTDIALOG_H

#include "resource.h"

#define NAME_ABOUT       "RPIClient"
#define VERSION_ABOUT    "1.0"
#define COPYRIGHT_ABOUT  "(c) elektron.ronca@gmail.com"
#define COMMENTS_ABOUT   "Free soft: you can redistribute it and/or modify it."
#define WEBSITE_ABOUT    "https://github.com/vroncevic/rpiclient-gtk"

typedef struct {
    GtkWidget *dialog;
} AboutDialog;

AboutDialog * new_about_dialog();
void show_about_dialog(AboutDialog *about_dialog_ptr);
void hide_about_dialog(AboutDialog *about_dialog_ptr);
void destroy_about_dialog(AboutDialog *about_dialog_ptr);

#endif

