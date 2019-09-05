/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * warningdialog.h
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
#ifndef __WARNINGDIALOG_H
#define __WARNINGDIALOG_H

#include "resource.h"

#define TITLE_WARNING_DIALOG	  "Warning!"
#define TEXT_WARNING_DIALOG	   "Please set ip address, port of server !"
#define ERROR_WARNINGS_DIALOG	 "There was an error !"
#define WARNING_WARNINGS_DIALOG   "Please make connection\nOption >> Connection"

typedef struct {
	GtkWidget *dialog;
} WarningDialog;

WarningDialog * new_warning_dialog(GtkWidget *parent, const gchar *msg);
void show_warning_dialog(WarningDialog *warning_dialog_ptr);
void hide_warning_dialog(WarningDialog *warning_dialog_ptr);
void destroy_warning_dialog(WarningDialog *warning_dialog_ptr);

#endif

