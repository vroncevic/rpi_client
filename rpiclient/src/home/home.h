/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * home.h
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

#include "menu_bar.h"
#include "home_frame.h"
#include "settings_config.h"
#include "rpiformat.h"

#define TITLE_RPICLIENT_WINDOW "RPIClient v1.0"
#define WIDTH_RPICLIENT_WINDOW (250)
#define HEIGHT_RPICLIENT_WINDOW (450)
#define CONTAINER_BORDER_WIDTH_RPICLIENT_WINDOW (2)

typedef struct
{
    GtkWidget *window;
    GtkWidget *vbox;
    MenuBar *menu_bar;
    HomeFrame *frame_home;
} Home;

Home *new_home(void);
void show_home(Home *instance);
void hide_home(Home *instance);
void destroy_home(Home *instance);
