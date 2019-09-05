/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * exitdialog.h
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
#ifndef __EXITDIALOG_H
#define __EXITDIALOG_H

#include "resource.h"

#define TITLE_EXIT_DIALOG   "Confirm Exit"
#define TEXT_EXIT_LABEL	 "Exit RPIClient ?"

typedef struct {
	GtkWidget *dialog;
	GtkWidget *label;
	GtkWidget *content_area;
} ExitDialog;

ExitDialog * new_exit_dialog(GtkWidget *widget);
gint show_exit_dialog(ExitDialog *exit_dialog_ptr);
void hide_exit_dialog(ExitDialog *exit_dialog_ptr);
void destroy_exit_dialog(ExitDialog *exit_dialog_ptr);

#endif

