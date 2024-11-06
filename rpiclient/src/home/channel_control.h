/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * channel_control.h
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

#include "../widgets/vertical_bar.h"

#define WARNING_LOG_FAILED_MALLOC_CHANNEL_CONTROL(id, msg) \
    "Failed to allocate memory for channel control " #id " " #msg "\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Channel control complex widget
///   control_channel_vertical_bar - Custom widget for channel control
///   control_channel_scale - Gtk scale widget for channel control
///   control_channel_spinner_adjustment - Gtk adjustment widget for channel control
///   control_channel_spinner_button - Gtk spinner widget for channel control
///   control_channel_gpio_check_box - Gtk check box widget for channel control
typedef struct
{
    GtkVB *control_channel_vertical_bar;
    GtkWidget *control_channel_scale;
    GtkAdjustment *control_channel_spinner_adjustment;
    GtkWidget *control_channel_spinner_button;
    GtkWidget *control_channel_gpio_check_box;
} ChannelControl;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget channel control
/// @return Channel control complex widget pointer
ChannelControl *new_channel_control(gint channel_id);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show channel control complex widget
/// @param instance is pointer to complex widget channel control
void show_channel_control(ChannelControl *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide channel control complex widget
/// @param instance is pointer to complex widget channel control
void hide_channel_control(ChannelControl *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy channel control complex widget
/// @param instance is pointer to complex widget channel control
void destroy_channel_control(ChannelControl *instance);
