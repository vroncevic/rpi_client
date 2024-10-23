/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * home_frame.h
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

#include <gtk/gtk.h>
#include "channel_status.h"
#include "channel_control.h"

#define MAX_CHANNELS_STATUS (8)
#define START_X_POSITION_VERTICAL_BAR_GET (0)
#define Y_POSITION_VERTICAL_BAR_GET (45)
#define START_X_POSITION_ACTIVATE_CHANNEL_GET (0)
#define Y_POSITION_ACTIVATE_CHANNEL_GET (1)
#define START_X_POSITION_LABEL_GET (0)
#define Y_POSITION_LABEL_GET (25)
#define SHIFT_X_POSITION_GET (120)

#define MAX_CHANNELS_CONTROL (8)
#define START_X_POSITION_VERTICAL_BAR_SET (0)
#define Y_POSITION_VERTICAL_BAR_SET (0)
#define START_X_POSITION_SCALE_SET (70)
#define Y_POSITION_SCALE_SET (0)
#define START_X_POSITION_SPINER_BUTTON_SET (0)
#define Y_POSITION_SPINER_BUTTON_SET (110)
#define START_X_POSITION_ACTIVATE_GPIO_SET (0)
#define Y_POSITION_ACTIVATE_GPIO_SET (150)
#define SHIFT_X_POSITION_SET (120)

//////////////////////////////////////////////////////////////////////////////
/// @brief Home frame complex widget
///   frame_home - 
///   vpanned - 
///   frame_status - 
///   fixed_status - 
///   channel_status - 
///   frame_control - 
///   fixed_control - 
///   channel_control - 
typedef struct
{
    GtkWidget *frame_home;
    GtkWidget *vpaned;
    GtkWidget *frame_status;
    GtkWidget *fixed_status;
    ChannelStatus *channels_status[MAX_CHANNELS_STATUS];
    GtkWidget *frame_control;
    GtkWidget *fixed_control;
    ChannelControl *channels_control[MAX_CHANNELS_CONTROL];
} HomeFrame;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget home frame
/// @return Home frame complex widget pointer
HomeFrame *new_home_frame(void);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show home frame complex widget
/// @param instance is pointer to complex widget home frame
void show_home_frame(HomeFrame *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide home frame complex widget
/// @param instance is pointer to complex widget home frame
void hide_home_frame(HomeFrame *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy home frame complex widget
/// @param instance is pointer to complex widget home frame
void destroy_home_frame(HomeFrame *instance);
