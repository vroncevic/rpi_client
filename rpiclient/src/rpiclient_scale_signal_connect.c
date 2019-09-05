/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * rpiclient_scale_signal_connect.c
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
#include "rpiclient.h"

void rpiclient_scale_signal_connect(RPIClient *rpiclient_ptr) {
    if(rpiclient_ptr) {
        g_signal_connect(
            G_OBJECT(rpiclient_ptr->ch1->scale), "value_changed",
            G_CALLBACK(set_value_pc), (gpointer) rpiclient_ptr->ch1->spinbuton
        );
    }
}

void set_value_pc(GtkWidget * widget, gpointer data) {
    GtkRange *range = (GtkRange *) widget;
    GtkWidget *spinbuton = (GtkWidget *) data;
    gtk_spin_button_set_value(
        GTK_SPIN_BUTTON(spinbuton),
        (gdouble) gtk_range_get_value(range)
    );
}

