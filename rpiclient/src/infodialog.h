/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * infodialog.h
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
#ifndef __INFODIALOG_H
#define __INFODIALOG_H

#include "resource.h"

typedef struct {
	GtkWidget *dialog;
} InfoDialog;

InfoDialog * new_info_dialog(GtkWidget *parent, const gchar *msg);
void show_info_dialog(InfoDialog *info_dialog_ptr);
void hide_info_dialog(InfoDialog *info_dialog_ptr);
void destroy_info_dialog(InfoDialog *info_dialog_ptr);

#endif

