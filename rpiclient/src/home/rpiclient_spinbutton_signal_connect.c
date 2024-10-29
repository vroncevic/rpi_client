/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiclient_spinbutton_signal_connect.c
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
// #include "rpiclient.h"

// void rpiclient_spinbutton_signal_connect(Home *rpiclient_ptr)
// {
//     if (rpiclient_ptr)
//     {
//         g_signal_connect(
//             G_OBJECT(rpiclient_ptr->ch1->spinbuton), "value_changed",
//             G_CALLBACK(set_value_sc), (gpointer)rpiclient_ptr->ch1->control_channel_scale);
//     }
// }

// void set_value_sc(GtkWidget *widget, gpointer data)
// {
//     GtkWidget *spinbuton = (GtkWidget *)widget;
//     GtkRange *range = (GtkRange *)data;
//     gtk_range_set_value(
//         range,
//         (gdouble)gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuton)));
// }
