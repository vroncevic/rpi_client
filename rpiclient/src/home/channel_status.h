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

#include <glib.h>
#include <gtk/gtk.h>
#include "../widgets/vertical_bar.h"

//////////////////////////////////////////////////////////////////////////////
/// @brief Channel status complex widget
typedef struct _ChannelStatus ChannelStatus;

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
/// @brief Gets check box from channel status complex widget
/// @param instance is pointer to complex widget channel status
/// @return Check box from complex widget channel status
GtkWidget* get_check_box_channel_status(ChannelStatus *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets label from channel status complex widget
/// @param instance is pointer to complex widget channel status
/// @return Label from complex widget channel status
GtkWidget* get_label_channel_status(ChannelStatus *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Gets bar from channel status complex widget
/// @param instance is pointer to complex widget channel status
/// @return Bar from complex widget channel status
GtkVB* get_bar_channel_status(ChannelStatus *instance);

//////////////////////////////////////////////////////////////////////////////
/// @brief Destroy channel status complex widget
/// @param instance is pointer to complex widget channel status
void destroy_channel_status(ChannelStatus *instance);
