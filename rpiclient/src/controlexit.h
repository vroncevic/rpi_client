/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * controlexit.h
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
#ifndef __CONTROLEXIT_H
#define __CONTROLEXIT_H

#include "resource.h"

#define TEXT_FRAME_EXIT		  "Exit Operation"
#define TEXT_CHECK_BUTTON_EXIT   "Display Exit Dialog on Quit?"

typedef struct {
	GtkWidget *frame;
	GtkWidget *control_exit;
} ControlExit;

ControlExit * new_control_exit();
void show_control_exit(ControlExit *control_exit_ptr);
void hide_control_exit(ControlExit *control_exit_ptr);
void destroy_control_exit(ControlExit *control_exit_ptr);

#endif

