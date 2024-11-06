/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * channel_status.h
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

#define WARNING_LOG_FAILED_MALLOC_CHANNEL_STATUS(id, msg) \
    "Failed to allocate memory for channel status " #id " " #msg "\n"

//////////////////////////////////////////////////////////////////////////////
/// @brief Channel status complex widget
///   activate_channel_check_box - Gtk check box widget for channel status
///   status_channel_label - Gtk label widget for channel mark
///   status_channel_vertical_bar - Custom widget for channel status
typedef struct
{
    GtkWidget *activate_channel_check_box;
    GtkWidget *status_channel_label;
    GtkVB *status_channel_vertical_bar;
} ChannelStatus;

//////////////////////////////////////////////////////////////////////////////
/// @brief Construct complex widget channel status
/// @return Channel status complex widget pointer
ChannelStatus *new_channel_status(gint channel_id);

//////////////////////////////////////////////////////////////////////////////
/// @brief Show channel status complex widget
/// @param instance is pointer to complex widget channel status
void show_channel_status(ChannelStatus *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Hide channel status complex widget
/// @param instance is pointer to complex widget channel status
void hide_channel_status(ChannelStatus *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy channel status complex widget
/// @param instance is pointer to complex widget channel status
void destroy_channel_status(ChannelStatus *instance);
