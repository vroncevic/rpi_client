/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiclient_vbar_signal_connect.c
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

// void rpiclient_vbar_signal_connect(Home *rpiclient_ptr)
// {
//     if (rpiclient_ptr)
//     {
//         g_signal_connect(
//             G_OBJECT(rpiclient_ptr->ch1->control_channel_scale), "value_changed",
//             G_CALLBACK(set_value_pb), (gpointer)rpiclient_ptr->ch1->vb);
//     }
// }

// void set_value_pb(GtkWidget *widget, gpointer data)
// {
//     GdkRegion *region;
//     GtkRange *range = (GtkRange *)widget;
//     GtkWidget *vb = (GtkWidget *)data;
//     GTK_VB(vb)->sel = gtk_range_get_value(range);
//     region = gdk_drawable_get_clip_region(vb->window);
//     gdk_window_invalidate_region(vb->window, region, TRUE);
//     gdk_window_process_updates(vb->window, TRUE);
//     gchar *name = gtk_widget_get_tooltip_text(data);
//     if (strcmp(name, TOOLTIP_TEXT_CPU_1) == 0)
//         rpi.channel_data[0] = (char)GTK_VB(vb)->sel;
//     if (strcmp(name, TOOLTIP_TEXT_CPU_2) == 0)
//         rpi.channel_data[1] = (char)GTK_VB(vb)->sel;
//     if (strcmp(name, TOOLTIP_TEXT_CPU_3) == 0)
//         rpi.channel_data[2] = (char)GTK_VB(vb)->sel;
//     if (strcmp(name, TOOLTIP_TEXT_CPU_4) == 0)
//         rpi.channel_data[3] = (char)GTK_VB(vb)->sel;
//     if (strcmp(name, TOOLTIP_TEXT_CPU_5) == 0)
//         rpi.channel_data[4] = (char)GTK_VB(vb)->sel;
//     if (strcmp(name, TOOLTIP_TEXT_CPU_6) == 0)
//         rpi.channel_data[5] = (char)GTK_VB(vb)->sel;
//     if (strcmp(name, TOOLTIP_TEXT_CPU_7) == 0)
//         rpi.channel_data[6] = (char)GTK_VB(vb)->sel;
//     if (strcmp(name, TOOLTIP_TEXT_CPU_8) == 0)
//         rpi.channel_data[7] = (char)GTK_VB(vb)->sel;
// }
